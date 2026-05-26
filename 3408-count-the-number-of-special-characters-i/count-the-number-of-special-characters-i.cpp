class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> small;
        unordered_set<char> big;

        for (char ch : word) {
            if (islower(ch))
                small.insert(ch);
            else
                big.insert(ch);
        }

        int count = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (small.count(ch) && big.count(ch - 'a' + 'A'))
                count++;
        }

        return count;
    }
};