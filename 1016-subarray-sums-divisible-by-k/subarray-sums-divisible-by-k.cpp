class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int prefixSum = 0;
        int count = 0;

        // Empty prefix has sum 0 and remainder 0
        mp[0] = 1;

        for (int num : nums) {
            prefixSum += num;

            int remainder = prefixSum % k;

            // C++ can produce negative remainders
            if (remainder < 0) {
                remainder += k;
            }

            // Every previous same remainder creates one valid subarray
            count += mp[remainder];

            mp[remainder]++;
        }

        return count;
    }
};