class Solution {
public:
int n;

int dp[50001];

    int getNext(vector<vector<int>>&arr,int start,int jobend){
        int ans=n;
        int r=n-1;
        while(start<=r){
            int mid= start+(r-start)/2;
            if(arr[mid][0]>=jobend){
                ans=mid;
                r=mid-1;
            }
            else 
           start=mid+1;
        }
        return ans;
    }

    int solve(vector<vector<int>>&arr,int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int next=getNext(arr,i+1,arr[i][1]);

        int taken=arr[i][2] + solve(arr,next);
        int skip= solve(arr,i+1);

        return dp[i]=max(taken,skip);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>arr(n,vector<int>(3));
        for(int i=0;i<n;i++){
            arr[i][0]=startTime[i];
            arr[i][1]=endTime[i];
            arr[i][2]=profit[i];
        }
        auto comp=[&](auto& vec1,auto& vec2){
            return vec1[0]<vec2[0];
        };
        sort(begin(arr),end(arr));
        return solve(arr,0);
    }
};