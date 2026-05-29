class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int close = nums[0]+nums[1]+nums[2];

        for(int i=0;i<n-1;i++){
            int left= i+1;
            int right=  n-1;
            while(left<right){
                int tempSum= nums[i]+nums[left]+nums[right];   
                if(abs(target- tempSum)< abs(target - close)){
                    close= tempSum;
                }
                if(tempSum==target){
                    return tempSum;
                }
                else if(tempSum< target) left++;

                else right--;
         }
        }
            return close;
    }

};