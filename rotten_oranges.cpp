#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh_count = 0;
        queue<pair<int,int>>q;
        vector<vector<int>>direction={{0,1},{1,0},{0,-1},{-1,0}};

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh_count++;
                }
            }
        }

        if(fresh_count == 0) return 0;
        q.push({-1,-1});
        int time = -1;

        while(!q.empty()){
            int r = get<0>(q.front()), c = get<1>(q.front());
            q.pop();
            if(r==-1 && c==-1){
                time++;
                if(!q.empty()){
                q.push({-1,-1});
                }
                continue;
            }

            for(vector<int> dir:direction){
                int nr = r+dir[0], nc = c+dir[1];
                if(nr<m && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc] = 2;     
                    fresh_count--;
                }
            }
        }

        if(fresh_count) return -1;
        return time;
    }
};

int main(){

    //testcases here
    
    return 0;
}