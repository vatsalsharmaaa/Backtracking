class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,-1);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<2*n ;j++){
                int id=j%n;
                if(nums[id]>nums[i]){
                    res[i]=nums[id]; break;
                }
            }
        }
        return res;
    }
};