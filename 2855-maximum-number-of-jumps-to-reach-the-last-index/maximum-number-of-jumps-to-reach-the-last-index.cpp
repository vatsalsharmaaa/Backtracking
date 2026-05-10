class Solution {
public:
    int n;
    int dp[1001];

    int solve(vector<int>& nums, int target, int i) {
        if (i == n - 1) return 0;

        if (dp[i] != -1) return dp[i];

        int result = INT_MIN;

        for (int j = i + 1; j < n; j++) {
            if (abs(nums[i] - nums[j]) <= target) {
                int steps = solve(nums, target, j);

                if (steps != INT_MIN) {
                    result = max(result, 1 + steps);
                }
            }
        }

        return dp[i] = result;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));

        int ans = solve(nums, target, 0);

        return (ans == INT_MIN) ? -1 : ans;
    }
};