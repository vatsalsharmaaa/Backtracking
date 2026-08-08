class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int res=0;
        for(auto x:nums){
            sum+=x;
            int remainder= sum%k;


            if(remainder<0){
                remainder+=k;
            }
            
            if(mp[remainder]>0){
                res+=mp[remainder];
            }
            mp[remainder]++;
        }
        return res;
    }
};