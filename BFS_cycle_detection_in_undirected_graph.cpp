#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool hasCycle(int V, unordered_map<int,list<int>>& adj, vector<bool>& vis, int parent, int node){
        queue<pair<int,int>>q;
        q.push({parent,node});
        vis[node] = true;
        while(!q.empty()){
            int p = get<0>(q.front());
            int v = get<1>(q.front());
            q.pop();
            for(auto neighbour:adj[v]){
                if(!vis[neighbour]){
                    q.push({neighbour,v});
                    vis[neighbour] = true;
                }else if(neighbour!=p){
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        unordered_map<int,list<int>>adjList;
        for(int i = 0; i<V; i++){
            for(int j = 0; j<adj[i].size(); j++){
                adjList[i].push_back(adj[i][j]);
            }
        }

        vector<bool>vis(V,false);
        bool ans = false;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(hasCycle(V,adjList,vis,-1,i)) return true;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<tuple<int, vector<vector<int>>, bool>> test_cases_cycle_detection_undirected = {

    // Test 1 — Simple cycle triangle
    {3, {{1,2}, {0,2}, {0,1}}, true},

    // Test 2 — No cycle, simple tree
    {4, {{1}, {0,2,3}, {1}, {1}}, false},

    // Test 3 — Disconnected graph, no cycle
    {5, {{}, {2}, {1}, {}, {}}, false},

    // Test 4 — Disconnected graph, one component has cycle
    {6, {{1}, {0,2}, {1,3,4}, {2,4}, {2,3}, {}} , true},

    // Test 5 — Single node, no cycle
    {1, {{}}, false},

    // Test 6 — Two nodes, one edge
    {2, {{1}, {0}}, false},

    // Test 7 — Two nodes, no edge
    {2, {{}, {}}, false},

    // Test 8 — Square cycle
    {4, {{1,3}, {0,2}, {1,3}, {0,2}}, true},

    // Test 9 — Tree shape, no cycle
    {5, {{1}, {0,2,3}, {1,4}, {1}, {2}}, false},

    // Test 10 — Star graph (center node connected to all others), no cycle
    {5, {{1,2,3,4}, {0}, {0}, {0}, {0}}, false},

    // Test 11 — Complex graph with multiple cycles
    {6, {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}}, true},

    // Test 12 — Empty graph (no edges)
    {4, {{}, {}, {}, {}}, false},

    // Test 13 — Large acyclic graph
    {7, {{1}, {0,2,3}, {1}, {1,4,5}, {3}, {3,6}, {5}}, false},

    // Test 14 — Large graph with a cycle
    {7, {{1,2}, {0,3}, {0,4}, {1,5}, {2,5}, {3,4,6}, {5}}, true}

};

cout<<"Result Expected"<<endl;
    for (int i = 0; i < test_cases_cycle_detection_undirected.size(); i++) {
        auto V = get<0>(test_cases_cycle_detection_undirected[i]);
        auto adj = get<1>(test_cases_cycle_detection_undirected[i]);
        auto expected = get<2>(test_cases_cycle_detection_undirected[i]);

        bool result = sol.isCycle(V, adj);  
        cout<<result <<" "<<expected<<endl;
    }

    return 0;
}