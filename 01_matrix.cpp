#include<bits/stdc++.h>
using namespace std;

//It has time complexity of O(M*N)
//It is a MULTI-SOURCE BFS SOLUTION
//IT GETS IMPLMENTED BY BFS IN ONE PASS ONLY

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> updatedMat(m,vector<int>(n,INT_MAX));
        vector<vector<int>>directions = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int,int>>q;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(mat[i][j]==0){
                    updatedMat[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto r = get<0>(q.front());
            auto c = get<1>(q.front());
            q.pop();
            for(auto dir : directions){
                int nr = r + dir[0], nc = c + dir[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    if(updatedMat[nr][nc] > updatedMat[r][c] + 1){
                        updatedMat[nr][nc] = updatedMat[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        return updatedMat;
    }
};

//Below is also a implemnetation but it has time complexigty of O(M*N*M*N)
//BELOW IS THE NORMAL ONE-O-ONE BFS SOLUTION THAT TAKE MUCH LONGER TIME


// class Solution {
// private:
//     int calculateDistance(int r, int c, vector<vector<int>>& mat){
//         int m = mat.size(), n = mat[0].size();
//         int count = 0;
//         vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
//         queue<tuple<int,int,int>>q;
//         q.push({r,c,count});

//         while(!q.empty()){
//             auto row = get<0>(q.front());
//             auto col = get<1>(q.front());
//             auto distance = get<2>(q.front());
//             q.pop();
//             for(vector<int> direction:dir){
//                 int v = direction[0], h = direction[1];
//                 if((row+v<m && row+v>=0)&&(col+h<n && col+h>=0)){
//                     if(mat[row+v][col+h]!=0){
//                         q.push({row+v,col+h,distance+1});
//                     }
//                     else return distance+1;
//                 }
//             }
//         }
//         return count;
//     }
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         vector<vector<int>> updatedMat = mat;
//         int m = mat.size(), n = mat[0].size();
//         for(int i = 0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 if(mat[i][j]!=0){
//                     updatedMat[i][j] = calculateDistance(i,j,mat);
//                 }
//             }
//         }
//         return updatedMat;
//     }
// };

int main(){
    Solution sol;
    vector<pair<vector<vector<int>>, vector<vector<int>>>> test_cases_01_matrix = {
    // Test 1: All zeros
    {
        {{0,0,0},
         {0,0,0},
         {0,0,0}},
        {{0,0,0},
         {0,0,0},
         {0,0,0}}
    },

    // Test 2: Single zero in center, all 1's around
    {
        {{1,1,1},
         {1,0,1},
         {1,1,1}},
        {{2,1,2},
         {1,0,1},
         {2,1,2}}
    },

    // Test 3: Mixed shape, zeros in first row and one zero in row1
    {
        {{0,0,0},
         {0,1,1},
         {1,1,1}},
        // Distances:
        // row0: all zeros → 0
        // row1: (1,0)=0→0; (1,1) nearest zero at (1,0) or (0,1) →1; (1,2) nearest zero (0,2) →1
        // row2: (2,0) nearest zero (1,0)→1; (2,1) nearest zero (1,1)->1 then to zero →2? Actually nearest zero is (0,1) dist 2 or (1,0) dist2 →2; (2,2) nearest zero (1,2) dist1? But (1,2) is 1, not zero. Nearest zero is (0,2) dist2. However also (1,1) is 1. So distance 2.
        // But careful BFS from zeros at (0,0),(0,1),(0,2),(1,0):
        //   (2,1): BFS distance = 2, (2,2): BFS distance = 2.
        {{0,0,0},
         {0,1,1},
         {1,2,2}}
    },

    // Test 4: All zeros small 2x2
    {
        {{0,0},
         {0,0}},
        {{0,0},
         {0,0}}
    },

    // Test 5: Single row mixed
    {
        {{1,0,1,1,0}},
        // distances: [1,0,1,1,0]
        {{1,0,1,1,0}}
    },

    // Test 6: Single column mixed
    {
        {{1},
         {0},
         {1},
         {1},
         {0}},
        // distances: [1,0,1,1,0]^T
        {{1},
         {0},
         {1},
         {1},
         {0}}
    },

    // Test 7: Single cell = 0
    {
        {{0}},
        {{0}}
    },

    // Test 8: Irregular shape with multiple zeros scattered
    {
        {{0,1,0,1},
         {1,1,1,0},
         {1,0,1,1}},
        // Zeros at (0,0),(0,2),(1,3),(2,1).
        // BFS distances:
        // row0: [0,1,0,1]
        // row1: (1,0) nearest (0,0)→1; (1,1) nearest (2,1)→1; (1,2) nearest (0,2)→1; (1,3)=0
        // row2: (2,0) nearest (2,1)→1; (2,1)=0; (2,2) nearest (2,1)→1; (2,3) nearest (1,3)→1
        {{0,1,0,1},
         {1,1,1,0},
         {1,0,1,1}}
    },

    // Test 9: Larger matrix, single zero in center
    {
        {{1,1,1,1},
         {1,1,1,1},
         {1,1,0,1},
         {1,1,1,1}},
        // Zero at (2,2). Distances = Manhattan distance to (2,2):
        // row0: (0,0)->4, (0,1)->3, (0,2)->2, (0,3)->3
        // row1: (1,0)->3, (1,1)->2, (1,2)->1, (1,3)->2
        // row2: (2,0)->2, (2,1)->1, (2,2)->0, (2,3)->1
        // row3: (3,0)->3, (3,1)->2, (3,2)->1, (3,3)->2
        {{4,3,2,3},
         {3,2,1,2},
         {2,1,0,1},
         {3,2,1,2}}
    },

    // Test 10: Zeros on corners/borders
    {
        {{0,1,1},
         {1,1,1},
         {1,1,0}},
        // Zeros at (0,0) and (2,2). BFS distances:
        // row0: (0,0)=0; (0,1)=1; (0,2)=2
        // row1: (1,0)=1; (1,1)=2; (1,2)=1
        // row2: (2,0)=2; (2,1)=1; (2,2)=0
        {{0,1,2},
         {1,2,1},
         {2,1,0}}
    },

    // Test 11: Empty matrix edge-case (depending on your implementation, you may check and return empty)
    {
        {}, 
        {}
    }
};

    for(auto testcase:test_cases_01_matrix){
        auto mat = get<0>(testcase);
        auto expected = get<0>(testcase);
        auto ans = sol.updateMatrix(mat);
        int m = ans.size();
        int n = ans[0].size();
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }
return 0;
}