 class Solution {
 public:
     vector<vector<int>>dirs={{0,-1},{-1,0},{0,1},{1,0}};
     int zero=0;
     int n,m;
     int result;
     int ti,tj;

     void solve(int i,int j,vector<vector<int>>& grid,int count){
          if(i<0||j<0||i>=n||j>=m||grid[i][j]==-1) return ;
         if(grid[i][j]==0)count++;
        
          if(i==ti &&j==tj ){
                if(count==zero){
                result++;
                 return;
                }
         }
       
         int temp = grid[i][j];
          grid[i][j] = -1;

         for(auto dir:dirs){
             int ni= i+ dir[0];
             int nj= j+dir[1];
            
            solve(ni,nj,grid,count);
         }
         grid[i][j]=temp;
     }
     int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
          m=grid[0].size();
          int si=0,sj=0;
          result=0;
          int count=0;

         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]==0) zero++; 
                 if(grid[i][j]==1) {
                     si=i;
                     sj=j;
                 }
                 if(grid[i][j]==2){
                     ti=i;
                    tj=j;
                }
             }

        }
        solve(si,sj,grid,count);
         return result;
    }
 };

// class Solution {
// public:
//     vector<vector<int>> dirs = {{0,-1},{-1,0},{0,1},{1,0}};
//     int zero = 0;
//     int n, m;
//     int result;
//     int ti, tj;

//     void solve(int i, int j, vector<vector<int>>& grid, int count) {

//         if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1)
//             return;

//         if(grid[i][j] == 0)
//             count++;

//         // Reached destination
//         if(i == ti && j == tj) {
//             if(count == zero)
//                 result++;
//             return;
//         }

//         int temp = grid[i][j];
//         grid[i][j] = -1;

//         for(auto &dir : dirs) {
//             int ni = i + dir[0];
//             int nj = j + dir[1];
//             solve(ni, nj, grid, count);
//         }

//         grid[i][j] = temp; // backtrack
//     }

//     int uniquePathsIII(vector<vector<int>>& grid) {

//         n = grid.size();
//         m = grid[0].size();

//         int si = 0, sj = 0;
//         result = 0;

//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {

//                 if(grid[i][j] == 0)
//                     zero++;

//                 if(grid[i][j] == 1) {
//                     si = i;
//                     sj = j;
//                 }

//                 if(grid[i][j] == 2) {
//                     ti = i;
//                     tj = j;
//                 }
//             }
//         }

//         solve(si, sj, grid, 0);

//         return result;
//     }
// };