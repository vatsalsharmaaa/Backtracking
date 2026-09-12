// class Solution {
// public:
//     vector<int> dp;

//     bool solve(int i, unordered_map<int, vector<int>>& mp, int n){
//         if(i == n){
//             return true;
//         }
//         if(dp[i] != -1) return dp[i];
//         if(mp.find(i) == mp.end()){
//             return false;
//         }

//         for(int j : mp[i]){
//             if(solve(j, mp, n)){
//                 return dp[i] = true;
//             }
//         }
//         return dp[i] = false;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n = s.length();
//         dp.resize(n, -1);

//         unordered_set<string> st(begin(wordDict), end(wordDict));

//         unordered_map<int, vector<int>> mp;

//         for(int i = 0; i<n; i++){
//             for(int j = i; j<n; j++){
//                 string temp = s.substr(i, j-i+1);
//                 if(st.count(temp)){
//                     mp[i].push_back(j+1);
//                 }
//             }
//         }

//         if(solve(0, mp, n)){
//             return true;
//         }
//         return false;
//     }
// };

class Solution {
public:
    int n;
    unordered_set<string>st;
    int dp[301];

    bool solve(int idx,string s){

        if(idx>=n) {
            return dp[idx]=true;
        }
        if(dp[idx]!=-1) return dp[idx];

        if(st.find(s)!=st.end())
        {
            return dp[idx]=true;
        }
        for(int i=1;i<=n;i++){
            string temp= s.substr(idx,i);
            if(st.find(temp)!=st.end()&&solve(idx+i,s)){
                return dp[idx]=true;
            }
        }

        return dp[idx]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();

        for(auto &word:wordDict){
            st.insert(word);
        }
       memset(dp,-1,sizeof(dp));

        return solve(0,s);
    }
};


















