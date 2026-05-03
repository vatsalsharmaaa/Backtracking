class Solution {
public:
    bool check(string s, string goal,int n,int i){
       reverse(s.begin(), s.begin() + (n - i));
       reverse(s.begin() + (n - i), s.end());
       reverse(s.begin(), s.end());
        if(s==goal) return true;

        return false;
    }
    bool rotateString(string s, string goal) {
        int n=s.length();
        int m=goal.length();
        if(n!=m) return false;

        for(int i=0;i<n;i++){
            if(check(s,goal,n,i)){
            return true;
            break;
            }
        }
        return false;
    }
};