class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        if(t.length()>n){
            return "";
        }
        unordered_map<char,int>mp;
        for(auto x:t){
            mp[x]++;
        }
        int reqCount = t.length();

        int i=0 , j=0;
        int min_window_size=INT_MAX;
        int start_i=0;
        while(j<n){
            char ch=s[j];
            if(mp[ch]>0){
                reqCount--;
            }
            mp[ch]--;
            while(reqCount==0){
                //shrinking the window
                int currwindow= j-i+1;

                if(min_window_size>currwindow){
                    min_window_size= currwindow;
                    start_i=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    reqCount++;
                }
                i++;
            }
            j++;
        }
        return min_window_size==INT_MAX?"": s.substr(start_i,min_window_size);
        
    }
};