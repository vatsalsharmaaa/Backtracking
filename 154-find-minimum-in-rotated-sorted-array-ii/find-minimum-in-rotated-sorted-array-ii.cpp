// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n=nums.size();
//         int l=0;
//         int r=n-1;
//         while(l<r &&nums[l]==nums[l+1]){
//             l++;
//         }
//          while(l<r&&nums[r]==nums[r-1]){
//            r--;
//         }
//         int minidx=0;
//         while(l<r){
//             int mid= l+(r-l)/2;
//             if(nums[mid]<nums[minidx]){
//                 minidx=mid;
//             }
//             if(nums[mid]>nums[r]){
               
//                 l=mid+1;
//             }
//             else r=mid-1;
//         }
//         return nums[minidx];
//     }
// };
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        while (l < r && nums[l] == nums[l + 1]) {
            l++;
        }

        while (l < r && nums[r] == nums[r - 1]) {
            r--;
        }

        int minidx = 0;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[minidx]) {
                minidx = mid;
            }

            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            else {
                r = mid;   // corrected from mid-1
            }
        }

        if (nums[l] < nums[minidx]) {
            minidx = l;
        }

        return nums[minidx];
    }
};