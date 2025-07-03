class Solution {
public:
    void expandAroundCenter(const string &s, int &left, int &right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {
        string answer = "";

        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;

            expandAroundCenter(s, left, right);
            string palindrom = s.substr(left + 1, right - left - 1);
            if (palindrom.size() > answer.size()) answer = palindrom;

            left = i; right = i + 1;
            expandAroundCenter(s, left, right);
            palindrom = s.substr(left + 1, right - left - 1);
            if (palindrom.size() > answer.size()) answer = palindrom;
        }

        return answer;
    }
};
