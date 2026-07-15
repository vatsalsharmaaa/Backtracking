class Solution {
public:
int n;
    int solve(string s,int k){

        if(s.length()==0) return 0;

        vector<int> mp(26,0);
        for(auto ch: s){
            mp[ch-'a']++;
        }
      
        for(int i=0;i<s.length();i++){
            if(mp[s[i]-'a'] <k){
                int left=solve(s.substr(0,i),k);
                int right= solve(s.substr(i+1),k);

                return max(left,right);   //max left right return hote chale jayenge upar
            }
        }


        return s.size();//means given string is already valid 

    }
    int longestSubstring(string s, int k) {
        n=s.length();

        return solve(s,k);
    }
};