class Solution {
public:
    bool checkPalByDel(string s, int start, int end){
        while(start<=end){
            if(s[start] == s[end]){
                start++;
                end--;
            }else{
                return false;
            }
        }

        return true;
    }
    bool validPalindrome(string s) {

        int size = s.length();
        int start = 0;
        int end = size-1;


        while(start<=end){
            if(s[start] == s[end]){
                start++;end--;
            }else{
                bool checkByDeleteStart = checkPalByDel(s,start+1,end);
                bool checkByDeleteEnd = checkPalByDel(s,start,end-1);

                return  checkByDeleteStart || checkByDeleteEnd;
                
            }
        }

        return true;
        
    }
};