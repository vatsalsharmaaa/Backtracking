class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;

        int f = 0;
        int s = 1;

        while (f < n && s < n) {
            if (nums[f] + nums[s] == target) {
                ans.push_back(f);
                ans.push_back(s);
                return ans;   
            }
            s++;   
            if (s == n) {  
                f++;
                s = f + 1;  
            }
        }

        return ans; 
    }
};
