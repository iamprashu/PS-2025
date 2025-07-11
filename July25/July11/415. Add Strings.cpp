class Solution {
public:
    
    void toAdd(string &num1, string &num2, int carry, int p1, int p2,string &answer){
        if(p1 < 0 && p2 < 0){
            if(carry!=0) answer.push_back(carry+'0');
            return ;
        }

        int n1 = (p1>=0? num1[p1] : '0' ) - '0'; // getting number 0 is char 0 and num x if char x ascii play
        int n2 = (p2>=0? num2[p2] : '0' ) - '0';

        int csum = n1 + n2 + carry; 
        int digit = csum % 10;
        carry = csum/10;
        answer.push_back(digit + '0');

        toAdd(num1,num2,carry,p1-1,p2-1,answer);
        


    }
    string addStrings(string num1, string num2) {
        string answer="";
        toAdd(num1,num2, 0, num1.size()-1, num2.size()-1, answer);

        reverse(answer.begin(), answer.end());

        return answer;
        
    }
};