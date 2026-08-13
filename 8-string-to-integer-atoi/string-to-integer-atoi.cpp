class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // 1. Skip leading spaces
        while(i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check sign
        int sign = 1;

        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            i++;
        }

        // 3. Build the number
        int ans = 0;

        while(i < n && s[i] >= '0' && s[i] <= '9') {

            int digit = s[i] - '0';

            // 4. Check overflow
            if(ans > (INT_MAX - digit) / 10) {
                if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        // 5. Apply sign
        return ans * sign;
    }
};