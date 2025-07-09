#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
private:
    vector<int>rank;
    vector<int>size;
    vector<int>parent;

public:
    DisjointSet(int N){
        //considering N nodes from 1 to N
        size.resize(N+1,1);
        rank.resize(N+1,0);
        parent.resize(N+1,0);
        
        for(int i = 1; i<=N; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node]==node) return node;
        int parentNode = findParent(parent[node]);
        parent[node] = parentNode;              //path compression
        return parentNode;
    }

    bool areInSameComponent(int u, int v){
        return findParent(u)==findParent(v);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;

        int rpu = rank[pu];
        int rpv = rank[pv];
        if(rpu>=rpv){
            parent[pv] = pu;
            rank[pu]++;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu==pv) return;

        int spu = size[pu];
        int spv = size[pv];
        if(spu>=spv){
            parent[pv] = pu;
            size[pu]+=size[pv];
        }else{
            parent[pu] = pv;
            size[pv]+=size[pu];
        }
    }

};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    cout<<ds.areInSameComponent(3,7)<<endl;
    ds.unionByRank(3,7);
    
    cout<<ds.areInSameComponent(3,7)<<endl;
}