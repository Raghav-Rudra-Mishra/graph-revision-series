//Cycle detection in directed graph can be done in 2 ways - DFS or BFS
//BFS is not something that is implmented directly but is implmented by Topological sort, kahn's algorithm which we will see later


#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool hasCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis){
        vis[node] = true;
        pathVis[node] = true;
        for(int nbr : adj[node]){
            if(!vis[nbr]){
                if(hasCycle(nbr,node,adj,vis,pathVis)) return true;
            }else if(pathVis[nbr]){
                return true;
            }
        }
        pathVis[node] = false;
        return false;
    }
public:
    bool isCyclic(int N, vector<vector<int>>& adj) {
        vector<bool>vis(N,false);
        vector<bool>pathVis(N,false);
        for(int i = 0; i<N; i++){
            if(!vis[i]){
                if(hasCycle(i,-1,adj,vis,pathVis)) return true;
            }
        }
        return false;
    }
};


int main(){
    Solution sol;
    vector<tuple<int, vector<vector<int>>, bool>> test_cases_directed_cycle_detection = {

    // Test 1 — Simple cycle
    {3, {{1}, {2}, {0}}, true}, // 0 → 1 → 2 → 0

    // Test 2 — Linear graph, no cycle
    {4, {{1}, {2}, {3}, {}}, false}, // 0 → 1 → 2 → 3

    // Test 3 — Disconnected graph with no cycle
    {5, {{1}, {}, {3}, {}, {}}, false},

    // Test 4 — Disconnected graph with one component cyclic
    {6, {{1}, {2}, {0}, {4}, {5}, {}}, true}, // 0→1→2→0 is cycle

    // Test 5 — Self-loop (cycle of length 1)
    {3, {{0}, {2}, {}}, true}, // 0 → 0 is a cycle

    // Test 6 — Single node, no edge
    {1, {{}}, false},

    // Test 7 — Single node with self-loop
    {1, {{0}}, true},

    // Test 8 — Cycle in the middle
    {6, {{1}, {2}, {3}, {1}, {5}, {}}, true}, // 1→2→3→1

    // Test 9 — Multiple components, one with cycle
    {7, {{1}, {2}, {}, {4}, {5}, {3}, {}}, true}, // 3→4→5→3

    // Test 10 — Multiple components, all acyclic
    {7, {{1}, {2}, {}, {4}, {}, {6}, {}}, false},

    // Test 11 — Complex acyclic DAG
    {6, {{1, 2}, {3}, {3}, {4}, {}, {}}, false}, // DAG: no cycle

    // Test 12 — Complex graph with back edge
    {6, {{1}, {2}, {3}, {1}, {5}, {}}, true}, // back edge 3→1 forms cycle

    // Test 13 — Large cycle involving all nodes
    {5, {{1}, {2}, {3}, {4}, {0}}, true}, // full cycle 0→1→2→3→4→0

    // Test 14 — Forked edges, but no cycle
    {5, {{1, 2}, {3}, {3}, {}, {}}, false},

    // Test 15 — V = 0 edge case (empty graph)
    {0, {}, false}
};

    cout<<"expected result"<<endl;

for(auto testcase:test_cases_directed_cycle_detection){
    int v = get<0>(testcase);
    vector<vector<int>> adj = get<1>(testcase);
    bool expected = get<2>(testcase);

    bool result = sol.isCyclic(v,adj);
    cout<<expected<<" "<<result<<endl;
}
    return 0;
}