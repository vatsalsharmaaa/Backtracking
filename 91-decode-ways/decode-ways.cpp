class Solution {
public:
    int dp[101];
    int solve(int i,int n,string &s){
        if(dp[i]!=-1) return dp[i];

        if(i==n){
            return dp[i]=1;
        }
        if(s[i]=='0')return dp[i]=0;

        int take1char= solve(i+1,n,s);
        int take2char=0;

        if(i+1<n ){
            if(s[i]=='1'|| (s[i]=='2' && s[i+1]<='6')){
                take2char=solve(i+2,n,s);
            }
        }
        
        return dp[i]=take1char+take2char;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        return solve(0,n,s);
    }
};