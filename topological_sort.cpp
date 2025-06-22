//this topological sort is implemented using dfs algorithm

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st){
    vis[node] = true;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,vis,adj,st);
        }
    }
    st.push(node);
}

vector<int> topoSort(vector<vector<int>>& adj){
    int v = adj.size();
    stack<int>st;
    vector<bool>vis(v,false);
    for(int i = 0; i<v; i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {

    // Vector of test graphs
    vector<vector<vector<int>>> test_cases = {

        // Test Case 1: Simple chain 0 → 1 → 2 → 3
        // Expected topo order: {0, 1, 2, 3}
        {
            {1},    // 0
            {2},    // 1
            {3},    // 2
            {}      // 3
        },

        // Test Case 2: Branching DAG
        // 0 → 1 → 4
        // 0 → 2 → 4
        // 0 → 3 → 5
        // Expected topo order example: {0, 1, 2, 3, 4, 5}
        {
            {1, 2, 3}, // 0
            {4},       // 1
            {4},       // 2
            {5},       // 3
            {},        // 4
            {}         // 5
        },

        // Test Case 3: Disconnected components
        // 0 → 1
        // 2 → 3 → 4
        // Expected topo order example: {0, 1, 2, 3, 4} or {2, 3, 4, 0, 1}
        {
            {1},    // 0
            {},     // 1
            {3},    // 2
            {4},    // 3
            {}      // 4
        },

        // Test Case 4: Complex DAG
        // 5 → 0 → 2 → 3
        // 5 → 2
        // 4 → 0
        // 4 → 1 → 3
        // Expected topo order example: {4, 5, 0, 1, 2, 3}
        {
            {2},        // 0
            {3},        // 1
            {3},        // 2
            {},         // 3
            {0, 1},     // 4
            {0, 2}      // 5
        },

        // Test Case 5: Single node (no edges)
        // Expected topo order: {0}
        {
            {}  // 0
        }

    };

    // Print info about test cases
    for (int i = 0; i < test_cases.size(); i++) {
        cout << "Test Case #" << i + 1 << ":\n";
        vector<vector<int>>& g = test_cases[i];
        vector<int> ans = topoSort(g);
        for (int u = 0; u < g.size(); u++) {
            cout<<ans[u]<<" ";
        }
        cout << "---------------------------\n";
    }

    // You can now pass each graph to your topological sort functions
    // Example:
    // for (auto& g : test_cases) {
    //     topological_sort_dfs(g);
    //     topological_sort_kahns(g);
    // }

    return 0;
}