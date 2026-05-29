class Solution {
public:
    vector<string> answer;
    vector<string> mp ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string &digits, int idx , string &curr){

        if(digits.length()==idx){
            answer.push_back(curr);
            return ;
        }
        int num= digits[idx]-'0';
        string alpha= mp[num];

        for(char c:alpha){
            curr.push_back(c);
            solve(digits,idx+1,curr);
            curr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        string curr="";
        solve(digits,0,curr);
        return answer;
    }
};