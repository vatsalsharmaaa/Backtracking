class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         int n=nums.size();
        unordered_map<int,int>mp;

        int res=0;
        int zero=0;
        int one=0;

        for(int i=0;i<n;i++){
            if(nums[i]==0) zero++;
            else one++;

            if(zero-one==0) res=max(res,i+1);
            else{
                int k=zero-one;
                if(mp.find(k)!=mp.end()){
                    res= max(res,i-mp[k]);
                }
                else mp[k]=i;
            }
        }      
        return res;
    }
};