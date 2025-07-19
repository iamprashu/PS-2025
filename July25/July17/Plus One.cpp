class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //triversing and getting it
        vector<int>answer;

        int i = digits.size()-1;
        int carry=1; // as we need to add
        while(i >= 0){
            int currentDigit = digits[i];
            long long sum = currentDigit + carry;
            carry = sum/10;
            long long digit = sum % 10;
            answer.push_back(digit);
            i--;
        }

        if(carry){
            answer.push_back(carry);
        }

        reverse(answer.begin(),answer.end());

        return answer;


            
    }
};