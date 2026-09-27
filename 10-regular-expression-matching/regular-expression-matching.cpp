class Solution {
public:
    int dp[21][21];
    bool solve(int i, int j,string s ,string p){
        if(j==p.length()){
             return dp[i][j]= i==s.length();
        }

        if(dp[i][j]!=-1) return dp[i][j];

        bool first_char_matched=false;
        if(i<s.length()&& (s[i]==p[j] || p[j]=='.')){
            first_char_matched=true;
        }
        if(p[j+1]=='*'){
            bool take;
            if(i<s.length()&&j<p.length())
            take= first_char_matched && solve(i+1,j,s,p);
            bool skip=solve(i,j+2,s,p);

             return dp[i][j]=take || skip;
        }
         return dp[i][j]=first_char_matched && solve(i+1,j+1,s,p);
    }
    bool isMatch(string s, string p) {
        memset (dp,-1,sizeof(dp));
        return solve( 0,0,s,p);
    }
};