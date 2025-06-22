//Dijkstra is implemented using priority queue
//Dijkstra's algorithm is the "shortest path finding algorithm" from source node to all the other nodes of a graph
//it requires non-negative edge weights
//graph can be either undirected or directed

//order of quality with implmentation : q -> pq -> set

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int,int>>>& adj){
    int n = adj.size();

    //spaces required
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;  //{dist,node}
    vector<int>dist(n,INT_MAX);

    //starters      considering 0 as a src node in this case
    dist[0]=0;
    pq.push({0,0});

    //algorithm                                     O(V+2E) is something that i thought, 
    //Time complexity ->>   o(E log V)
    while(!pq.empty()){
        auto distance = get<0>(pq.top());
        auto node = get<1>(pq.top());
        pq.pop();

        for(auto ele:adj[node]){
            int v = ele.first, w = ele.second;
            if(distance+w<dist[v]){
                dist[v] = distance+w;
                pq.push({dist[v],v});
            }
        }
    }

    return dist;

}

int main(){
// A test case is a vector of adjacency lists: vector<vector<pair<int, int>>>
vector<vector<vector<pair<int, int>>>> testCases = {
    // Test Case 1: Simple linear graph
    {
        {{1, 2}},         // 0 connects to 1 with weight 2
        {{0, 2}, {2, 3}}, // 1 connects to 0 (2), 2 (3)
        {{1, 3}, {3, 4}}, // 2 connects to 1 (3), 3 (4)
        {{2, 4}}          // 3 connects to 2 (4)
    },
    // Expected distances from node 0: {0, 2, 5, 9}
    
    // Test Case 2: Star graph
    {
        {{1, 1}, {2, 1}, {3, 1}, {4, 1}}, // 0 connects to 1,2,3,4 with weight 1
        {{0, 1}},                         // 1 connects to 0
        {{0, 1}},                         // 2 connects to 0
        {{0, 1}},                         // 3 connects to 0
        {{0, 1}}                          // 4 connects to 0
    },
    // Expected distances from node 0: {0, 1, 1, 1, 1}
    
    // Test Case 3: Complete graph
    {
        {{1, 1}, {2, 2}, {3, 3}}, // 0 connects to 1 (1), 2 (2), 3 (3)
        {{0, 1}, {2, 1}, {3, 1}}, // 1 connects to 0 (1), 2 (1), 3 (1)
        {{0, 2}, {1, 1}, {3, 2}}, // 2 connects to 0 (2), 1 (1), 3 (2)
        {{0, 3}, {1, 1}, {2, 2}}  // 3 connects to 0 (3), 1 (1), 2 (2)
    },
    // Expected distances from node 0: {0, 1, 2, 2}
    
    // Test Case 4: Disconnected graph
    {
        {{1, 5}},    // 0 connects to 1 with weight 5
        {{0, 5}},    // 1 connects to 0
        {{3, 7}},    // 2 connects to 3 with weight 7
        {{2, 7}}     // 3 connects to 2
    },
    // Expected distances from node 0: {0, 5, INF, INF}
    
    // Test Case 5: Single node
    {
        {}           // 0 has no connections
    },
    // Expected distances from node 0: {0}
    
    // Test Case 6: Cycle graph
    {
        {{1, 1}, {3, 4}}, // 0 connects to 1 (1), 3 (4)
        {{0, 1}, {2, 2}}, // 1 connects to 0 (1), 2 (2)
        {{1, 2}, {3, 3}}, // 2 connects to 1 (2), 3 (3)
        {{2, 3}, {0, 4}}  // 3 connects to 2 (3), 0 (4)
    }
    // Expected distances from node 0: {0, 1, 3, 4}
};

    for(int u = 0; u<testCases.size(); u++){
        vector<vector<pair<int,int>>> t = testCases[u];
        vector<int>ans = dijkstra(t);
        cout<<"Testcase "<<u<<endl;
        for(int i = 0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}