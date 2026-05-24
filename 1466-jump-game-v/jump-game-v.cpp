class Solution {
public:
    int n;
    int dp[100001];

    int solve(int i,int d,vector<int>&arr){
        if(dp[i]!=-1) return dp[i];
        int result=1;

        // left
        for(int j= i-1 ;j >=max(0,i-d);j--){
            if(arr[j]>=arr[i]) break;
            result= max(result,1+solve(j,d,arr));
        }
         for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j]>=arr[i]) break;
            result= max(result,1+solve(j,d,arr));
        }
        return dp[i]= result;
    }
    int maxJumps(vector<int>& arr, int d) {
        n=arr.size();
        memset(dp,-1,sizeof(dp));
        int result=1;
        for(int i=0;i<n;i++){
            result= max(result, solve(i,d,arr));
        }
        return result;

    }
};