class Solution {
public:
    int n,m;
    int dp[71][71][71];

    int solve(vector<vector<int>>& grid,int row,int col1,int col2){

        if(row>=n){
            return dp[row][col1][col2]= 0;
        }
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];


        int cherry=0;
        cherry+=grid[row][col1];
        if(col1!=col2){
            cherry+=grid[row][col2];
        }
        int ans=0;

        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){

                int ncol1= i+col1;
                int ncol2= j+col2;
                int nrow= row+1;

                if(ncol1>=0 &&ncol1<m && ncol2>=0 &&ncol2<m)
                 ans= max(ans,solve(grid,nrow,ncol1,ncol2));

            }
        }
        return dp[row][col1][col2]=cherry + ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(grid,0,0,m-1);
    }
};