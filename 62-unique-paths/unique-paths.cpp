// class Solution {
// public:
//     int dp [101][101];

//     int solve(int i,int j,int m,int n){
//         if(i==m-1 && j==n-1){
//             return 1;
//         }
//         if(i<0 || i>=m || j<0 ||j>=n){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int down=solve(i+1,j,m,n);
//         int right= solve(i,j+1,m,n);

//         return dp[i][j]=down + right;
//     }
//     int uniquePaths(int m, int n) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,0,m,n);
//     }
// };

class Solution {
public: 
    int dp[101][101];
    int uniquePaths(int m, int n) {
        dp[0][0]=1; // 0,0 pe pahochne ke 0,0 se kitne tarike h?? 1 hi h 
        for(int col=1;col<=n;col++){
            dp[0][col]=1;
        }
        for(int row=1;row<=m;row++){
            dp[row][0]=1;   
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]= dp[i-1][j]+ dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};