class Solution {
public:
typedef long long ll;
    long long maxTotalValue(vector<int>& nums, int k) {
       ll maxi=INT_MIN;
        ll mini=INT_MAX;
        for(auto x:nums){
            if (x>maxi) maxi=x;
            if(x<mini) mini =x;
        }
        return (maxi-mini)*k;
    }
};