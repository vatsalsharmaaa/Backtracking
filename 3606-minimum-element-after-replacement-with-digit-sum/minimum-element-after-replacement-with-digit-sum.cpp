class Solution {
public:
    int sumDigits(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minElement(vector<int>& nums) {
        int mini = INT_MAX;

        for (int num : nums) {
            mini = min(mini, sumDigits(num));
        }

        return mini;
    }
};