class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int res = nums[0];
        int prev = nums[0];

        int res1 = nums[0];
        int prev1 = nums[0];

        int sum = nums[0];

        for (int i = 1; i < n; i++) {
            int curr = max(nums[i], nums[i] + prev);
            res = max(res, curr);
            prev = curr;

            int curr1 = min(nums[i], nums[i] + prev1);
            res1 = min(res1, curr1);
            prev1 = curr1;

            sum += nums[i];
        }

        if (res < 0) {
            return res;
        }

        int circularSum = sum - res1;

        return max(res, circularSum);
    }
};