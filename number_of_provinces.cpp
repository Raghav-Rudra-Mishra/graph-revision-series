#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, unordered_map<int,list<int>>& adjList, vector<bool>& visited){
        visited[node] = true;
        for(auto e:adjList[node]){
            if(!visited[e]){
                dfs(e,adjList,visited);
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        unordered_map<int,list<int>>adjList;
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                if(i!=j && isConnected[i][j]==1) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        vector<bool>visited(V,false);
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                dfs(i,adjList,visited);
                count++;
            }
        }
        
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<vector<int>>> test_cases_provinces = {

    // Example 1 — From LeetCode
    {{1,1,0},
     {1,1,0},
     {0,0,1}}, // Expected: 2

    // Example 2 — Single province (fully connected)
    {{1,1,1},
     {1,1,1},
     {1,1,1}}, // Expected: 1

    // Example 3 — Disconnected nodes (3 separate)
    {{1,0,0},
     {0,1,0},
     {0,0,1}}, // Expected: 3

    // Example 4 — Single node
    {{1}}, // Expected: 1

    // Example 5 — Two nodes, connected
    {{1,1},
     {1,1}}, // Expected: 1

    // Example 6 — Two nodes, not connected
    {{1,0},
     {0,1}}, // Expected: 2

    // Example 7 — Larger graph, mixed
    {{1,1,0,0,0}, 
     {1,1,1,0,0}, 
     {0,1,1,0,0}, 
     {0,0,0,1,1}, 
     {0,0,0,1,1}}, // Expected: 2

    // Example 8 — Empty graph (edge case)
    {}, // Expected: 0

    // Example 9 — One large province with tail
    {{1,1,0,0,1},
     {1,1,1,0,0},
     {0,1,1,0,0},
     {0,0,0,1,0},
     {1,0,0,0,1}}, // Expected: 2

    // Example 10 — 4 nodes, all separate
    {{1,0,0,0},
     {0,1,0,0},
     {0,0,1,0},
     {0,0,0,1}} // Expected: 4

};

for(int i = 0; i<test_cases_provinces.size(); i++){
    vector<vector<int>>testcase = test_cases_provinces[i];
    cout<<sol.findCircleNum(testcase)<<endl;
}
return 0;
}