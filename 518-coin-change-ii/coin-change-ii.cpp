class Solution {
public:
    int n;
    int dp[301][5001];

    int solve(int idx,int amount,vector<int>&coins){
        if(idx==n)return dp[idx][amount]= 0;
        if(amount==0){
            return dp[idx][amount]=1;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        long long take=0;
         if(coins[idx]<=amount)
         take= solve(idx,amount-coins[idx],coins);
        long long skip=solve(idx+1,amount,coins);
         return dp[idx][amount]=skip+take;
        
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
         return solve(0,amount,coins);
    }
};