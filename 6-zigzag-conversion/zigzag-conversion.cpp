class Solution {
public:
    string convert(string s, int num_rows) {
        if (num_rows == 1) {
            return s;
        }
        string ans;
        int n = s.size();
        int char_in_section = 2 * (num_rows - 1);

        for (int curr_row = 0; curr_row < num_rows; curr_row++) {
            int index = curr_row;
            while (index < n) {
                ans += s[index];
                if (curr_row != 0 && curr_row != num_rows - 1) {
                    int char_in_between = char_in_section - 2 * (curr_row);
                    int second_index = index + char_in_between;

                    if (second_index < n) {
                        ans += s[second_index];
                    }
                }
                index += char_in_section;
            }
        }
        return ans;
    }
};