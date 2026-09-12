class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int rightEven = 0, rightOdd = 0;

        // Initially everything is on right side
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0)
                rightEven += nums[i];
            else
                rightOdd += nums[i];
        }

        int leftEven = 0, leftOdd = 0;
        int count = 0;

        for(int i = 0; i < n; i++) {

            // Remove current element from right
            if(i % 2 == 0)
                rightEven -= nums[i];
            else
                rightOdd -= nums[i];

            // After deletion, right side parity flips
            int evenSum = leftEven + rightOdd;
            int oddSum  = leftOdd + rightEven;

            if(evenSum == oddSum)
                count++;

            // Add current element to left for next iteration
            if(i % 2 == 0)
                leftEven += nums[i];
            else
                leftOdd += nums[i];
        }

        return count;
    }
};