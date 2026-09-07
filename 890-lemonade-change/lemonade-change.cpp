class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        int tty = 0;

        if(bills[0] != 5) return false;

        for(int i = 0; i < n; i++) {

            if(bills[i] == 5) {
                five++;
            }

            else if(bills[i] == 10) {
                if(five < 1) return false;

                five--;
                ten++;
            }

            else if(bills[i] == 20) {
                tty++;

                // Prefer 10 + 5
                if(five >= 1 && ten >= 1) {
                    five--;
                    ten--;
                }
                // Otherwise 5 + 5 + 5
                else if(five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};