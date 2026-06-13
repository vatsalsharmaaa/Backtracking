// class Solution {
// public:
//     vector<vector<int>>dirs={{1,2},{-1,2},{-1,-2},{1,-2},{2,1},{2,-1},{-2,-1},{-2,1}};
//     int dp[26][26][101];

//     double solve(int n,int i,int j,int k){
//         if(i<0||i>=n||j<0||j>=n) return dp[i][j][k]=0.0;
//         if(k==0) return dp[i][j][k]=1.0;
//         if(dp[i][j][k]!=-1) return dp[i][j][k];
//         double ans=0;

//         for(auto dir:dirs){
//             int ni=i+dir[0];
//             int nj= j+dir[1];

//             ans+= double(solve(n,ni,nj,k-1));
//         }
//         return dp[i][j][k]=double(ans/8.0);
//     }
//     double knightProbability(int n, int k, int row, int col) {
//         memset(dp,-1,sizeof(dp));
//         return solve(n,row,col,k);
   
//     }
// };
class Solution {
public:
    vector<vector<int>> dirs = {
        {1,2},{-1,2},{-1,-2},{1,-2},
        {2,1},{2,-1},{-2,-1},{-2,1}
    };

    double dp[26][26][101];

    double solve(int n, int i, int j, int k) {
        if (i < 0 || i >= n || j < 0 || j >= n)
            return 0.0;

        if (k == 0)
            return 1.0;

        if (dp[i][j][k] != -1.0)
            return dp[i][j][k];

        double ans = 0.0;

        for (auto &dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            ans += solve(n, ni, nj, k - 1);
        }

        return dp[i][j][k] = ans / 8.0;
    }

    double knightProbability(int n, int k, int row, int col) {
        fill(&dp[0][0][0], &dp[0][0][0] + 26*26*101, -1.0);
        return solve(n, row, col, k);
    }
};