class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        if(s.length() != t.length()){ // as anagram should be same in length
            return false;
        }

        for(int i=0; i<s.length(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};