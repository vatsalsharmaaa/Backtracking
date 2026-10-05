class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int>tillnow;
        int n=s.length();
        int score=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                tillnow.push_back(score);
                score=0;
            }
            else{
                if(s[i-1]=='('){
                    score = tillnow.back()+1; //simple case;
                }
                else {
                    score= tillnow.back() + (2*score);
                }
                tillnow.pop_back();
            }
        }
        
        return score;
    }
};