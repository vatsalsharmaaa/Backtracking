// class Solution {
// public:
//     int dp[401];
//     int n;

//     int solve(vector<int>&nums, int idx){
//         if(idx>n) return 0;

//         if(dp[idx]!=-1) return dp[idx];

//         int take=0;
//         if(idx<n)
//         take+= nums[idx]+ solve(nums,idx+2);

//         int skip=solve(nums,idx+1);
//         return dp[idx]=max(take,skip);
//     }
//     int rob(vector<int>& nums) {
//         n=nums.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(nums,0);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> dp(3, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp[2] = max(dp[0] + nums[2], dp[1]);

        for(int i = 3; i < n; i++) {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(nums[i] + dp[0], dp[1]);
        }

        return dp[2];
    }
};
















