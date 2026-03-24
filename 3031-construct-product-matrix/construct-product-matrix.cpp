class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD =12345;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>res(n,vector<int>(m));
        long long suff=1;
        long long pre=1;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i][j]=suff;
                suff=(suff*grid[i][j])%MOD;
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res[i][j]=(pre*res[i][j])%MOD;
                pre=(pre*grid[i][j])%MOD;
            }
        }
        return res;
    }
};