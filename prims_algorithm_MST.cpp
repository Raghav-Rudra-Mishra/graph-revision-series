#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getMST(int V, vector<vector<int>>& edges){
    unordered_map<int,list<pair<int,int>>>adj;
    for(vector<int> edge:edges){
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});    //only if graph is undirected and mine is
    }
    vector<pair<int,int>> mst_list;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
    vector<bool> vis(V,false);
    int sum = 0;
    
    pq.push({0,0,-1});       //initial configuratin to start from node 0
    while(!pq.empty()){
        int edgeWeight = get<0>(pq.top());
        int node = get<1>(pq.top());
        int parent = get<2>(pq.top());
        pq.pop();

        if(vis[node]) continue;
        sum+=edgeWeight;
        vis[node] = true;
        if(parent!=-1) mst_list.push_back({parent,node});
        for(auto nbr:adj[node]){
            int element = nbr.first, edgeCost = nbr.second;
            if(!vis[element]){
                pq.push({edgeCost,element,node});
            }
        }
    }

    return mst_list;
}

void printMST(int V, vector<vector<int>>& edges) {
    auto mst = getMST(V, edges);
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