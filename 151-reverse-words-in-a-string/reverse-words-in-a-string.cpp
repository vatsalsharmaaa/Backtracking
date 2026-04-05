class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string token = "";
        stringstream ss(s);
        
        while (ss >> token) {
            res = token + " " + res;
        }
        
        if (!res.empty()) res.pop_back();
        
        return res;
    }
};