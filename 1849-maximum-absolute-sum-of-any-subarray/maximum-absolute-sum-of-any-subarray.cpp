class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int maxi = nums[0];
        int mini = nums[0];

        int prevMax = nums[0];
        int prevMin = nums[0];

        for (int i = 1; i < n; i++) {

            prevMax = max(nums[i], prevMax + nums[i]);
            maxi = max(maxi, prevMax);

            prevMin = min(nums[i], prevMin + nums[i]);
            mini = min(mini, prevMin);
        }

        return max(abs(maxi), abs(mini));
    }
};