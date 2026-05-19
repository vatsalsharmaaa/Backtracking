// class Solution {
// public:
//     int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
//         int mx = max(nums1.back(), nums2.back());

//         vector<int> freq(mx + 1, 0);

//         for (auto x : nums1) {
//             freq[x]++;
//         }

//         for (auto y : nums2) {
//             freq[y]++;
//         }

//         for (int i = 0; i <= mx; i++) {
//             if (freq[i] >= 2) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {

            if (nums1[i] == nums2[j])
                return nums1[i];

            else if (nums1[i] < nums2[j])
                i++;

            else
                j++;
        }

        return -1;
    }
};