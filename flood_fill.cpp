#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;

        int m = image.size(), n = image[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>direction = {{0,1},{1,0},{0,-1},{-1,0}};
        q.push({sr,sc});

        int prev = image[sr][sc];   
        /*
        1) this is very important to get the previous color before; don't do this inside a loop or wyou will suffer with tle. 
        2) More to that visited array in ths question works by the color change of flood. so its always a good practice to mark the array visited before, thatswhy we marked the color change before tracing all the neihgbours.
        */

        while(!q.empty()){
            pair<int,int> ele = q.front();
            int r = ele.first, c = ele.second;
            q.pop();
            image[r][c] = color;
            for(vector<int> dir:direction){
                int vertical = dir[0], horizontal = dir[1];
                if((r+vertical<m && r+vertical>=0) && (c+horizontal<n && c+horizontal>=0) && image[r+vertical][c+horizontal]==prev){
                    q.push({r+vertical,c+horizontal});
                }
            }
        }
        return image;
    }
};

int main(){
    Solution sol;
    vector<tuple<vector<vector<int>>, int, int, int, vector<vector<int>>>> test_cases_flood_fill = {
    // Example 1 — From LeetCode
    {
        {{1,1,1},
         {1,1,0},
         {1,0,1}}, 1, 1, 2,
        {{2,2,2},
         {2,2,0},
         {2,0,1}}
    },

    // Example 2 — Entire image same color
    {
        {{0,0,0},
         {0,0,0}}, 0, 0, 2,
        {{2,2,2},
         {2,2,2}}
    },

    // Example 3 — Starting point already the color
    {
        {{0,0,0},
         {0,1,1}}, 1, 1, 1,
        {{0,0,0},
         {0,1,1}}
    },

    // Example 4 — Single pixel image
    {
        {{1}}, 0, 0, 5,
        {{5}}
    },

    // Example 5 — No matching neighbors
    {
        {{0,0,0},
         {0,2,0},
         {0,0,0}}, 1, 1, 3,
        {{0,0,0},
         {0,3,0},
         {0,0,0}}
    },

    // Example 6 — Large region flood
    {
        {{1,1,1,1,1},
         {1,1,0,0,1},
         {1,0,1,0,1},
         {1,1,1,1,1}}, 0, 0, 9,
        {{9,9,9,9,9},
         {9,9,0,0,9},
         {9,0,1,0,9},
         {9,9,9,9,9}}
    },

    // Example 7 — Irregular shape
    {
        {{1,2,1},
         {2,2,2},
         {1,2,1}}, 1, 1, 3,
        {{1,3,1},
         {3,3,3},
         {1,3,1}}
    },

    // Example 8 — Empty image (edge case)
    {
        {}, 0, 0, 1,
        {}
    }
};
    //run here

    return 0;
}