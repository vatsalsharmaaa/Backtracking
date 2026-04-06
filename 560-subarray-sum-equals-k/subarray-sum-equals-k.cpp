class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        int sum=0;
        mp[sum]++;
        int count=0;

        int n=nums.size();
       
        for(int i=0;i<n;i++){
             sum+=nums[i];
           
            
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
             mp[sum]++;
        }
        return count;
    }
};