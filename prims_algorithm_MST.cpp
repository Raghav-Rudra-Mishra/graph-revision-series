#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getMST(int V, vector<vector<int>>& edges){
    unordered_map<int,list<pair<int,int>>>adj;
    for(vector<int> edge:edges){
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v,w});
    }
    vector<pair<int,int>> mst_list;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
    vector<bool> vis(V,false);
    
    pq.push({0,0,-1});       //initial configuratin to start from node 0
    while(!pq.empty()){
        int edgeWeight = get<0>(pq.top());
        int node = get<1>(pq.top());
        int parent = get<2>(pq.top());
        pq.pop();

        if(vis[node]) continue;
        vis[node] = true;
        mst_list.push_back({parent,node});
        for(auto nbr:adj[node]){
            int element = nbr.first, edgeCost = nbr.second;
            if(!vis[element]){
                pq.push({edgeCost,element,node});
            }
        }
    }

    return mst_list;
}

int main(){
    //main code
    return 0;
}