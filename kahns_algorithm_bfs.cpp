//kahn's algorithm is a bfs way of getting the topological sort of the directed acyclic graph
//the same is used to for cycle detection in a graph by bfs

#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>>& adj){
    int v = adj.size();
    vector<int> indegree(v,0);
    queue<int>q;
    vector<int> ans;

    for(vector<int> vec:adj){
        for(int i = 0; i<vec.size(); i++){
            indegree[vec[i]]++;
        }
    }

    for(int i = 0; i<v; i++){
        if(!indegree[i]) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(int nbr:adj[node]){
            indegree[nbr]--;
            if(!indegree[nbr]){
                q.push(nbr);
            }
        }
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