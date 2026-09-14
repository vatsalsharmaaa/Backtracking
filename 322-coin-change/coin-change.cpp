// class Solution {
// public:
// int dp[10010];
// int func(int amount,vector<int>&coins){
//  if(amount==0) return 0;
//  if(dp[amount]!=-1) return dp[amount];
//         int ans=INT_MAX;
//         for(auto coin : coins){
//             if(amount - coin>=0){
//                 ans= min(ans+0ll,func(amount - coin , coins)+1ll);

//             } 
//         }
//      return dp[amount]= ans;
        
// }
//     int coinChange(vector<int>& coins, int amount) {
        
//        memset(dp,-1,sizeof(dp));
//        int ans= func(amount,coins);
//         return ans==INT_MAX?-1:ans;
        
//     }
// };









class Solution {
public:
int n;
int dp[13][10001];
    int solve(int idx,int amount,vector<int>&coins){
    
        if(amount==0) return dp[idx][amount]=0;
        
        if(amount<0 ||idx>=n)return 1e9;

        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take= 1+solve(idx,amount-coins[idx],coins);
        int skip=solve(idx+1,amount,coins);
        return dp[idx][amount]=min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
         n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans= solve(0,amount,coins);
        if(ans>=1e9) return -1;
        return ans;
    }
};















