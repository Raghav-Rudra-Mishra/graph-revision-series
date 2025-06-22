//this is a problme to print the shortest path from node '0' to 'n-1' in the graph, considering them as source and destination respectively.


#include<bits/stdc++.h>
using namespace std;

void printShortestPath(vector<vector<pair<int,int>>>& adj){
    int n = adj.size();
    //space required
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n);

    //starters
    pq.push({0,0});
    dist[0] = 0;
    for(int i = 0; i<n; i++){
        parent[i] = i;
    }

    //algorithm
    while(!pq.empty()){
        auto distance = get<0>(pq.top());
        auto node = get<1>(pq.top());
        pq.pop();

        for(auto ele:adj[node]){
            int v = ele.first, w = ele.second;
            if(distance+w<dist[v]){
                dist[v] = distance+w;
                pq.push({dist[v],v});
                parent[v] = node;
            }
        }
    }

    //a check

    if(dist[n-1] == INT_MAX){
    cout << "No path";
    return;
}

//get path otherwise
    vector<int> ans;
    int i = n-1;
    while(dist[i]!=0){
        ans.push_back(i);
        i = parent[i];
    }
    ans.push_back(i);
    reverse(ans.begin(),ans.end());
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}


int main(){
    vector<vector<vector<pair<int, int>>>> testCases = {
    // Test Case 1
    {
        {{1, 2}},
        {{0, 2}, {2, 3}},
        {{1, 3}, {3, 4}},
        {{2, 4}}
    },
    // Expected path: {0, 1, 2, 3}

    // Test Case 2
    {
        {{1, 1}, {2, 5}, {3, 2}, {4, 10}},
        {{0, 1}},
        {{0, 5}},
        {{0, 2}},
        {{0, 10}}
    },
    // Expected path: {0, 4}

    // Test Case 3
    {
        {{1, 1}, {2, 10}},
        {{0, 1}, {3, 1}},
        {{0, 10}, {3, 1}},
        {{1, 1}, {2, 1}}
    },
    // Expected path: {0, 1, 3}

    // Test Case 4 (Disconnected)
    {
        {{1, 2}},
        {{0, 2}},
        {{3, 5}},
        {{2, 5}}
    },
    // Expected path: none

    // Test Case 5 (Cycle)
    {
        {{1, 1}, {3, 4}},
        {{0, 1}, {2, 2}},
        {{1, 2}, {3, 3}},
        {{0, 4}, {2, 3}}
    }
    // Expected path: {0, 3}
};
    for(int u = 0; u<testCases.size(); u++){
        vector<vector<pair<int,int>>> t = testCases[u];
        printShortestPath(t);
        cout<<endl;
    }
    return 0;
}