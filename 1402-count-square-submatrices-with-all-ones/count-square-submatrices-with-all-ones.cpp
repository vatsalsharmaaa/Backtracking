// class Solution {
// public:
//     int n,m;
    int dp[301][301];
//     int solve(int i,int j,vector<vector<int>>& matrix){
//         if(i>=n||j>=m) return dp[i][j]=0;
//         if(matrix[i][j]==0)return dp[i][j]=0;

//         if(dp[i][j]!=-1)return dp[i][j];

//         int right= solve(i+1,j,matrix);
//         int down=solve(i,j+1,matrix);
//         int diag= solve(i+1,j+1,matrix);

//         return dp[i][j]=1+min({right,down,diag});
//     }
//     int countSquares(vector<vector<int>>& matrix) {
//          n=matrix.size();
//          m=matrix[0].size();

        // memset(dp,0,sizeof(dp));
//         int result=0;

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(matrix[i][j]==1)
//                 result+=solve(i,j,matrix);
//             }
//         }

//         return result;
//     }
// };


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
         memset(dp,0,sizeof(dp));

        int res=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i==0 || j==0){
                    dp[i][j]= matrix[i][j]; //1 hoga toh 1 aaa jayega 0 hoga to 0
                }
                else if(matrix[i][j]==1)
                dp[i][j]= 1+ min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});

                res+= dp[i][j];
            }
            
        }

        return res;
    }
};