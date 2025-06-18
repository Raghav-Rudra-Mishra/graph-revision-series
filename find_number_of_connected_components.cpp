#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

    void dfs(int node, unordered_map<int,list<int>>& adj, vector<bool>& vis){
      vis[node] = true;
      for(int neighbour:adj[node]){
        if(!vis[neighbour]){
          dfs(neighbour,adj,vis);
        }
      }
    }

    int findNumberOfComponent(int V, vector<vector<int>> &edges) {
      unordered_map<int,list<int>>adj;
      for(vector<int> edge:edges){
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }

      int componentCount = 0;
      vector<bool>vis(V,false);
      for(int node = 0; node<V; node++){
        if(!vis[node]){
          componentCount++;
          dfs(node,adj,vis);
        }
      }
      return componentCount;
    }

int main(){
    vector<pair<int,vector<vector<int>>>>test_cases={
        {7, {{0, 1}, {1, 2}, {2, 3}, {4, 5}}},         // Output: 3
        {5, {{0, 1}, {1, 2}, {3, 4}}},                 // Output: 2
        {1, {}},                                       // Output: 1
        {4, {}},                                       // Output: 4
        {4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}},         // Output: 1
        {6, {{0, 1}, {2, 3}, {4, 5}}},                 // Output: 3
        {6, {{0, 1}, {1, 2}}},                         // Output: 4
        {4, {{0, 0}, {1, 2}, {2, 3}}},                 // Output: 2
        {3, {{0, 1}, {1, 0}, {1, 2}, {2, 1}}},         // Output: 1
        {5, {{0, 1}, {0, 2}, {0, 3}, {0, 4}}},         // Output: 1
        {1000, {}}                                     // Output: 1000
    };

    for(auto test_case:test_cases){
        int V = test_case.first;
        vector<vector<int>>edges = test_case.second;
        cout<<findNumberOfComponent(V,edges)<<endl;
    }
    return 0;
}

