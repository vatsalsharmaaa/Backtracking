class Solution {
public:

    bool canDistribute(int mid,vector<int>& candies, long long k){
        long long count=0;

        for(auto c:candies){
            count+=c/mid;
        }
        return count>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(),candies.end());
        int n=candies.size();
        int left=1;
        int right=candies[n-1];
        int ans=0;
        while(left<=right){
            int mid= left+(right-left)/2;
            if(canDistribute(mid,candies,k)){
                ans=mid;
                left=mid+1;
            }
            else {
                right=mid-1;
            }
        }
        return ans;

    }
};