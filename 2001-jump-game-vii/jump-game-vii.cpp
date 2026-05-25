// class Solution {
// public:
//     int dp[100001];
//     int n;

//     bool solve(int idx, string &s, int mini, int maxi) {

//         if (idx == n - 1)
//             return true;

//         if (dp[idx] != -1)
//             return dp[idx];

//         for (int jump = mini; jump <= maxi; jump++) {

//             int j = idx + jump;

//             if (j >= n)
//                 break;

//             if (s[j] == '0') {

//                 if (solve(j, s, mini, maxi))
//                     return dp[idx] = true;
//             }
//         }

//         return dp[idx] = false;
//     }

//     bool canReach(string s, int minJump, int maxJump) {

//         memset(dp, -1, sizeof(dp));

//         n = s.size();

//         return solve(0, s, minJump, maxJump);
//     }
// };
// class Solution {
// public:
//     bool canReach(string s, int minJump, int maxJump) {

//         int n = s.size();

//         vector<int> dp(n, 0);

//         dp[0] = 1;

//         for (int i = 0; i < n; i++) {

//             if (!dp[i]) 
//                 continue;

//             for (int jump = minJump; jump <= maxJump; jump++) {

//                 int j = i + jump;

//                 if (j >= n)
//                     break;

//                 if (s[j] == '0')
//                     dp[j] = 1;
//             }
//         }

//         return dp[n - 1];
//     }
// };
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.size();

        vector<int> dp(n, 0);

        dp[0] = 1;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            if (i - minJump >= 0)
                reachable += dp[i - minJump];

            if (i - maxJump - 1 >= 0)
                reachable -= dp[i - maxJump - 1];

            if (reachable > 0 && s[i] == '0')
                dp[i] = 1;
        }

        return dp[n - 1];
    }
};