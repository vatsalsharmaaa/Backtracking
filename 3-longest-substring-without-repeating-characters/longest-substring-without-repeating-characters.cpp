class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>freq(256,false);


        int left=0;
        int right=0;
        int n=s.length();
        if(n==0) return 0;

        int maxlen=INT_MIN;
        while(right<n){

            while(freq[s[right]]){
                freq[s[left]]=false;
                left++;
            }
            freq[s[right]]=true;

            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};