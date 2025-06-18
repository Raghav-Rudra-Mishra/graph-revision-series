#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,list<int>>& adj, vector<bool>& vis, vector<int>& ansDFS){
    vis[node] = true;
    for(int neighbour:adj[node]){
        if(!vis[neighbour]){
            ansDFS.push_back(neighbour);
            dfs(neighbour,adj,vis, ansDFS);
        }
    }
}
    
vector<int> dfsOfGraph(int V, vector<vector<int>>& adj) {
    unordered_map<int,list<int>>adjList;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<adj[i].size(); j++){
            int u = i, v = adj[i][j];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    vector<int>ansDFS;
    vector<bool>vis(V,false);

    for(int node = 0; node<V; node++){
        if(!vis[node]){
            ansDFS.push_back(node);
            dfs(node,adjList,vis,ansDFS);
        }
    }

    return ansDFS;
}
    
vector<int> bfsOfGraph(int V, vector<vector<int>>& adj) {
    unordered_map<int,list<int>>adjList;
    for(int i = 0; i<V; i++){
        for(int j = 0; j<adj[i].size(); j++){
            int u = i, v = adj[i][j];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    vector<int>ansBFS;
    vector<bool>vis(V,false);
    
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            queue<int>q;
            q.push(i);
            vis[i] = true;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                ansBFS.push_back(node);
            
                for(int neighbour:adjList[node]){
                    if(!vis[neighbour]){
                        vis[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }

    return ansBFS;
}

int main(){
    vector<pair<int, vector<vector<int>>>> test_cases_traversal = {
    // Test Case 1
    {5, {{2, 3, 1}, {0}, {0, 4}, {0}, {2}}} 
    // DFS: 0 2 4 3 1    BFS: 0 2 3 1 4

    // Test Case 2 — Fully connected small graph
    ,{4, {{1, 2, 3}, {0, 2, 3}, {0, 1, 3}, {0, 1, 2}}} 
    // DFS: 0 1 2 3      BFS: 0 1 2 3

    // Test Case 3 — Star graph
    ,{5, {{1, 2, 3, 4}, {0}, {0}, {0}, {0}}} 
    // DFS: 0 1 2 3 4    BFS: 0 1 2 3 4

    // Test Case 4 — Line graph
    ,{6, {{1}, {0, 2}, {1, 3}, {2, 4}, {3, 5}, {4}}} 
    // DFS: 0 1 2 3 4 5  BFS: 0 1 2 3 4 5

    // Test Case 5 — Disconnected graph
    ,{6, {{1}, {0}, {3}, {2}, {5}, {4}}} 
    // DFS: 0 1          BFS: 0 1
    // (rest are disconnected if start=0)

    // Test Case 6 — Single node
    ,{1, { { } }} 
    // DFS: 0            BFS: 0

    // Test Case 7 — Two nodes, no edge
    ,{2, { {}, {} }} 
    // DFS: 0            BFS: 0

    // Test Case 8 — Tree
    ,{7, {{1, 2}, {3, 4}, {5, 6}, {}, {}, {}, {}}} 
    // DFS: 0 1 3 4 2 5 6   BFS: 0 1 2 3 4 5 6

    // Test Case 9 — Graph with cycle
    ,{4, {{1, 3}, {0, 2}, {1, 3}, {0, 2}}} 
    // DFS: 0 1 2 3      BFS: 0 1 3 2

    // Test Case 10 — Bigger sparse graph
    ,{8, {{1}, {0, 2, 3}, {1}, {1, 4, 5}, {3}, {3}, {7}, {6}}} 
    // DFS: 0 1 2 3 4 5   BFS: 0 1 2 3 4 5
    // node 6,7 are separate so not reached from 0
};


    for (int i = 0; i < test_cases_traversal.size(); i++) {
    int V = test_cases_traversal[i].first;
    vector<vector<int>> adj = test_cases_traversal[i].second;

    vector<int> dfs_result = dfsOfGraph(V, adj);  // Example: run DFS from node 0
    vector<int> bfs_result = bfsOfGraph(V, adj);  // Example: run BFS from node 0

    cout << "Test Case " << i+1 << ":\n";
    cout << "DFS: ";
    for (int x : dfs_result) cout << x << " ";
    cout << "\nBFS: ";
    for (int x : bfs_result) cout << x << " ";
    cout << "\n\n";
}

    return 0;
}

