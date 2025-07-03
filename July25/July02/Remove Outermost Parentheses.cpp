class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer;
        int count = 0;

        for(auto bracket : s){
            if(bracket == '('){
                if(!count==0){
                    answer.push_back(bracket);
                }
                count++;
            }else{
                if(count>1){
                    answer.push_back(bracket);
                }
                count--;
            }
        }

        return answer;
        
    }
};