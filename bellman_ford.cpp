//bellman ford is the shortest distance finding algorithm from the src node to all other nodes of the graph which also works for negative edges as well

#include<bits/stdc++.h>
using namespace std;

//Time complexity = O(V*E),
//Space complexity = O(N)

vector<int> shortest_distance_by_bellmanFord(int N, vector<vector<int>>& edges){
    vector<int>distance(N,INT_MAX);
    distance[0]=0;      //considering '0' as source node 
    for(int i = 0; i<N-1; i++){
        for(vector<int> edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(distance[u]+w<distance[v]){
                distance[v] = distance[u]+w;
            }
        }
    }
    //Ideally upto N-1 iterations all nodes must get their shortest distance and no updation is required. But if in Nth iteration any updation is still find then that graph has a "negative cycle" and it will keep on updating endlessly. for such case we do return {-1}.
    for(vector<int> edge:edges){
        int u = edge[0], v = edge[1], w = edge[2];
        if(distance[u]+w<distance[v]){
            return {-1};
        }
    }

    return distance;
}

int main(){

}