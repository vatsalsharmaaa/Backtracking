// class Solution {
// public:
//     bool buddyStrings(string s, string goal) {
//         if(s.size()!=goal.size()) return false;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 swap(s[i],s[j]);
//                 if(s==goal) return true;
//                 else swap(s[i],s[j]);
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool checkfreq(string s){
        vector<char>freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a']>1)
            return true;

        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        int m=goal.size();

        if(n!=m) return false;

        if(s==goal){
            return checkfreq(s);
        }

        vector<int>idx;

        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                idx.push_back(i);
            }
        }
        if(idx.size()!=2) return false;
        else{
            swap(s[idx[0]],s[idx[1]]);
            if(s==goal) return true;
        }
        return false;
    }
};