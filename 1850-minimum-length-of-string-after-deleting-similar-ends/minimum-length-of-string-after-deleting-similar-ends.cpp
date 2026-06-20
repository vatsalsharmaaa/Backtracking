class Solution {
public:
    int minimumLength(string s) {
        int low = 0;
        int high = s.size() - 1;

        while (low < high && s[low] == s[high]) {
            char ch = s[low];

            while (low <= high && s[low] == ch)
                low++;

            while (low <= high && s[high] == ch)
                high--;
        }

        return high - low + 1;
    }
};