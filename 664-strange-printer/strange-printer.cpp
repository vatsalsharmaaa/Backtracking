class Solution {
public:
   int dp[101][101];

    int solve(int i,int j,string s){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans= 1+solve(i+1,j,s);
        for(int k=i+1;k<=j;k++){
            if(s[i]==s[k])
            ans=min(ans,solve(i+1,k-1,s)+solve(k,j,s));
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        string t="";
        for(auto c:s){
            if(t.empty()||t.back()!=c){
                t.push_back(c);
            }
        }
        int m= t.size();
        return solve(0,m-1,t);
    }
};