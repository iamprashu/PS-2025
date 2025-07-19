class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();

        int i = size-1;
        // removing the white space from the end
        while(i >= 0 && s[i] == ' '){i--;};

        int count = 0;
        while(i >= 0 && s[i] != ' ') {count++; i--;};

        return count;
    }
};