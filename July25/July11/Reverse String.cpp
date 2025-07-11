// 344. Reverse String
class Solution {
public:
    void reverseThis(vector<char>&s,int &start,int &end){
        //base
        if(start>end){
            return;
        }
        //reverse 1 step
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;

        //call
        reverseThis(s,start,end);

    }
    void reverseString(vector<char>& s) {
        int start=0;
        int end = s.size()-1;
        reverseThis(s,start,end);
    }
};