class Solution {
public:
    
    vector<vector<int>>res;
    void solve(int idx,int target,vector<int>&nums,vector<int>&curr){
        if(target==0){
            res.push_back(curr);
            return ;
        }
        if(target>0){
            curr.push_back(nums[idx]);
            solve(idx,target-nums[idx],nums,curr);
            curr.pop_back();
        }
       
        if(idx+1<nums.size())
        solve(idx+1,target,nums,curr);
       

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        solve(0,target,candidates,curr);
        return res;
    }
};