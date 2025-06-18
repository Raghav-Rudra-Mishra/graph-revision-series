#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX - 10000)); // prevent overflow

        // First pass: top-left
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if(i > 0) dist[i][j] = min(dist[i][j], dist[i-1][j] + 1);
                    if(j > 0) dist[i][j] = min(dist[i][j], dist[i][j-1] + 1);
                }
            }
        }

        // Second pass: bottom-right
        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i < m-1) dist[i][j] = min(dist[i][j], dist[i+1][j] + 1);
                if(j < n-1) dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
            }
        }

        return dist;
    }
};

int main(){

    //testcase input
    return 0;
}
