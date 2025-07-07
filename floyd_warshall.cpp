#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> shortestDistanceByFloydWarshall(int V, vector<vector<int,int>>& edges){
    vector<vector<int>>costMatrix(V,vector<int>(V,INT_MAX));
    int n = edges.size();
    for(int i = 0; i<V; i++) costMatrix[i][i]=0;
    for(int i = 0 ; i<n; i++){
        int u = edges[i][0], v = edges[i][1], w = edges[i][2];
        costMatrix[u][v]=w;
    }

    for(int k = 0; k<V; k++){
        for(int i = 0; i<V; i++){
            for(int j = 0; j<V; j++){
                costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k]+costMatrix[j][k]);
            }
        }
    }

    for(int i = 0; i<V; i++){
        for(int j = 0; j<V; j++){
            if(costMatrix[i][j]==INT_MAX) costMatrix[i][j] = -1;
        }
    }

    return costMatrix;

}

int main(){
    //main code
    return 0;
}