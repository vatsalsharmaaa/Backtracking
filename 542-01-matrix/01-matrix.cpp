// class Solution {
// public:
//     int n, m;

//     vector<vector<int>> dirs = {
//         {0,1}, {1,0}, {-1,0}, {0,-1}
//     };

//     int bfs(int si, int sj, vector<vector<int>>& mat) {

//         queue<pair<int,int>> q;
//         vector<vector<int>> visited(n, vector<int>(m, 0));

//         q.push({si, sj});
//         visited[si][sj] = 1;

//         int dist = 0;

//         while(!q.empty()) {

//             int size = q.size();

//             while(size--) {

//                 auto [i, j] = q.front();
//                 q.pop();

//                 // nearest zero found
//                 if(mat[i][j] == 0)
//                     return dist;

//                 for(auto dir : dirs) {

//                     int ni = i + dir[0];
//                     int nj = j + dir[1];

//                     if(ni >= 0 && nj >= 0 &&
//                        ni < n && nj < m &&
//                        !visited[ni][nj]) {

//                         visited[ni][nj] = 1;
//                         q.push({ni, nj});
//                     }
//                 }
//             }

//             dist++;
//         }

//         return -1;
//     }

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

//         n = mat.size();
//         m = mat[0].size();

//         vector<vector<int>> res(n, vector<int>(m));

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {

//                 if(mat[i][j] == 0)
//                     res[i][j] = 0;
//                 else
//                     res[i][j] = bfs(i, j, mat);
//             }
//         }

//         return res;
//     }
// };

class Solution {
public:
    int n, m;

    vector<vector<int>> dirs = {
        {0,1}, {1,0}, {-1,0}, {0,-1}
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        n = mat.size();
        m = mat[0].size();

        vector<vector<int>> res(n, vector<int>(m, -1));

        queue<pair<int,int>> q;

        // Put all 0 cells into queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {

            auto [i, j] = q.front();
            q.pop();

            for(auto dir : dirs) {

                int ni = i + dir[0];
                int nj = j + dir[1];

                if(ni >= 0 && nj >= 0 &&
                   ni < n && nj < m &&
                   res[ni][nj] == -1) {

                    res[ni][nj] = res[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return res;
    }
};