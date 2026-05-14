class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);

        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
            }
        }

        if (maxi != n - 1) return false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 || nums[i] > n - 1)
                return false;

            freq[nums[i]]++;
        }

        for (int i = 1; i < maxi; i++) {
            if (freq[i] != 1)
                return false;
        }

        if (freq[maxi] != 2)
            return false;

        return true;
    }
};