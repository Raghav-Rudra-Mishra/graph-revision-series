//kruskals algorithm provides minimium spanning tree using disjoint set data structure

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

vector<pair<int,int>> getMSTByKruskals(int N, vector<vector<int>>&edges){
    sort(edges.begin(),edges.end(),[](const vector<int>& a, const vector<int>& b){
        return a[2]<b[2];
    });

    vector<pair<int,int>> MSTList;
    int edgeSumMST = 0;
    DisjointSet ds(N);
    for(vector<int> &edge:edges){
        int u = edge[0], v = edge[1], w = edge[2];
        if(ds.areInSameComponent(u,v)) continue;
        MSTList.push_back({u,v});
        edgeSumMST+=w;
        ds.unionBySize(u,v);
    }
    return MSTList;
}

void printMST(int V, vector<vector<int>>& edges) {
    auto mst = getMSTByKruskals(V, edges);
    int totalCost = 0;
    cout << "MST Edges:\n";
    for (auto& e : mst) {
        for (auto& edge : edges) {
            if ((edge[0] == e.first && edge[1] == e.second) || (edge[0] == e.second && edge[1] == e.first)) {
                totalCost += edge[2];
                break;
            }
        }
        cout << e.first << " - " << e.second << "\n";
    }
    cout << "Total MST cost: " << totalCost << "\n\n";
}


int main() {
    // 🔹 Test Case 1
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    cout << "🔹 Test Case 1\n";
    printMST(V1, edges1);

    // 🔹 Test Case 2
    int V2 = 4;
    vector<vector<int>> edges2 = {
        {0, 1, 1},
        {0, 2, 2},
        {0, 3, 3},
        {1, 2, 4},
        {2, 3, 5}
    };
    cout << "🔹 Test Case 2\n";
    printMST(V2, edges2);

    // 🔹 Test Case 3
    int V3 = 3;
    vector<vector<int>> edges3 = {
        {0, 1, 10},
        {1, 2, 15},
        {0, 2, 5}
    };
    cout << "🔹 Test Case 3\n";
    printMST(V3, edges3);

    // 🔹 Test Case 4
    int V4 = 6;
    vector<vector<int>> edges4 = {
        {0, 1, 3}, {0, 3, 1},
        {1, 2, 1}, {1, 3, 3},
        {2, 3, 1}, {2, 4, 6},
        {3, 4, 5}, {4, 5, 2},
        {2, 5, 4}
    };
    cout << "🔹 Test Case 4\n";
    printMST(V4, edges4);

    return 0;
}