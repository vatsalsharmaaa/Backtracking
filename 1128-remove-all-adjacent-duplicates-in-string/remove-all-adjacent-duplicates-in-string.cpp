class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length();
        stack<char>st;

        int i=0;
        while(i<n){
            char c=s[i];
            if(!st.empty()&&st.top()==c){
                st.pop();
            }
            else st.push(c);
            i++;
        }
        string ans="";
        while(st.size()>0){
            ans=st.top()+ans;
            st.pop();

        }
        return ans;
    }
};