class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();
        
        vector<int> chars(257, 0);

        for(int i = 0; i < n; i++){
            chars[password[i]] += 1;
        }
        int points = 0;

        for(int i = 0; i <= 256; i++){
            if(i >= 'A' && i <= 'Z' && chars[i] > 0) points += 2;
            else if(i >= '0' && i <= '9' && chars[i] > 0) points += 3;
            else if(i >= 'a' && i <= 'z' && chars[i] > 0) points += 1;
            else if(chars[i] > 0) points += 5;
        }

        return points;
    }
};