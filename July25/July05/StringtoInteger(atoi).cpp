class Solution {
public:
    bool isNumber(char &val) {
        return (val >= '0' && val <= '9');
    }

    void removeSpaces(string &str) {
        int n = str.length();
        int i = 0, j = -1;
        bool spaceFound = false;

        while (++j < n && str[j] == ' ');

        while (j < n) {
            if (str[j] != ' ') {
                if ((str[j] == '.' || str[j] == ',' || str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ')
                    str[i - 1] = str[j++];
                else
                    str[i++] = str[j++];
                spaceFound = false;
            } else if (str[j++] == ' ') {
                if (!spaceFound) {
                    str[i++] = ' ';
                    spaceFound = true;
                }
            }
        }

        str.erase(str.begin() + i, str.end());
    }

    int toNumber(char &val) {
        std::unordered_map<char, int> charToInt = {
            {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4},
            {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}
        };
        return charToInt[val];
    }

    int myAtoi(string s) {
        removeSpaces(s);
        if (s.empty()) return 0;

        bool isNegative = false;
        int i = 0;

        if (s[i] == '-') {
            isNegative = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        long long result = 0;
        while (i < s.size() && isNumber(s[i])) {
            int digit = toNumber(s[i]);
            result = result * 10 + digit;

            if (!isNegative && result > INT_MAX) return INT_MAX;
            if (isNegative && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return isNegative ? -result : result;
    }
};
