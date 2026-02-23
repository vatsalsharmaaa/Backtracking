class Solution {
public:
    int dp[201][1001];
    int n;
    int solve(vector<int>&nums,int target,int idx){
        if(target==0) return 1;

        if(idx>=n ||target<0) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];

        int take= solve(nums,target-nums[idx],0); // idx 0 se shuru hoga ab

        int skip= solve(nums,target,idx+1);
        return dp[idx][target]=take+skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);
    }
};