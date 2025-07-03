class Solution {
public:
    bool checkV(char &c){
        return (c == 'a' || c == 'e' || c=='i' || c == 'o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');    // checking each    
    }
    void swapThem(char &a, char &b){
        char temp = b;
        b = a;
        a = temp;
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start<=end){
            //case 1 jo happy hoga
            if(checkV(s[start]) && checkV(s[end])){
                swapThem(s[start],s[end]);
                start++;
                end--;
            //case 2 ):
            }else if(!checkV(s[start])){
                start ++;
            //no more posiblities as Constraints me sab saaf hai
            }else if(!checkV(s[end])){
                end--;
            }

        }

        return s;
    }
};