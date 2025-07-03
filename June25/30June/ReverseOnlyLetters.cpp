// https://leetcode.com/problems/reverse-only-letters/description/


class Solution {
public:
    bool checkA(char &c){
        return ((c >= 65 && c<=90 )|| (c>=97 && c<=122));    // checking each    
    }
    void swapThem(char &a, char &b){
        char temp = b;
        b = a;
        a = temp;
    }

    string reverseOnlyLetters(string s) {
        //using modified rotation technique in which i am gona add the conditions
        // as i can compare the other char that are not alphabet will be less than 65
        //using this ASCII hlp i will do crack this question

        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            //case 1 jo happy hoga
            if(checkA(s[start]) && checkA(s[end])){
                swapThem(s[start],s[end]);
                start++;
                end--;
            //case 2 ):
            }else if(!checkA(s[start])){
                start ++;
            //no more posiblities as Constraints me sab saaf hai
            }else if(!checkA(s[end])){
                end--;
            }

        }

        return s;
        
    }
};