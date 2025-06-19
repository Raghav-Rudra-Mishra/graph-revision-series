#include<bits/stdc++.h>
using namespace std;


//1. This one is the slowest solution ----> BFS + lots of space complexity

class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>direction = {{0,1},{1,0},{0,-1},{-1,0}};
        q.push({r,c});
        vis[r][c] = true;
        while(!q.empty()){
            auto row = get<0>(q.front());
            auto col = get<1>(q.front());
            q.pop();
            for(auto dir:direction){
                int nr = row+dir[0], nc = col+dir[1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]=='1'&& !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0]. size();
        int count = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};



//2. this one is sightly better ----> dfs + visited array

class Solution {
    private:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        grid[i][j]=2;
        if(i-1>=0 && grid[i-1][j]=='1') dfs(grid,i-1,j);
        if(i+1<m && grid[i+1][j]=='1') dfs(grid,i+1,j);
        if(j-1>=0 && grid[i][j-1]=='1') dfs(grid,i,j-1);
        if(j+1<n && grid[i][j+1]=='1') dfs(grid,i,j+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1'){
                    count++;
                dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};


//3. this one is most good solution no extra space just recursive stack ---> dfs only in recusion

class Solution {
public:
    bool island(int row, int col, vector<vector<char>>& grid){
        if(row>=0 && row<grid.size() && col>=0 && col<grid[0].size() && grid[row][col]=='1') return true;
        return false;
    }

    void nums(int i, int j, vector<vector<char>>& grid){

        grid[i][j]='0';

        if(island(i,j+1,grid)){
            nums(i,j+1,grid);
        }
        if(island(i+1,j,grid)){
            nums(i+1,j,grid);
        }
        if(island(i,j-1,grid)){
            nums(i,j-1,grid);
        }
        if(island(i-1,j,grid)){
            nums(i-1,j,grid);
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    nums(i,j,grid);
                    count++;
                }
            }
        }

        return count;
    }
};