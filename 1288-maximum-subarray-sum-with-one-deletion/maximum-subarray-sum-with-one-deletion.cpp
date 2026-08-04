class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int noDelete = arr[0];
        int oneDelete = arr[0];
        int result = arr[0];

        for (int i = 1; i < n; i++) {
            int prevNoDelete = noDelete;
            int prevOneDelete = oneDelete;

            // Either start new subarray or extend previous subarray
            noDelete = max(arr[i], prevNoDelete + arr[i]);

            // Case 1: Delete current arr[i]
            // Case 2: Deletion already happened, include arr[i]
            oneDelete = max(prevNoDelete,
                            prevOneDelete + arr[i]);

            result = max(result, max(noDelete, oneDelete));
        }

        return result;
    }
};