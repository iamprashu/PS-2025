class Solution {
public:
    void recursion(vector<string>&answer,int n,int openBrackets,int closeBrackets,string s){
        if(openBrackets == n && closeBrackets == n){
            answer.push_back(s);
            return;
        }

        if(openBrackets < n){
            recursion(answer,n,openBrackets+1,closeBrackets,s+"(");
        }

        if(closeBrackets < openBrackets){
            recursion(answer,n,openBrackets,closeBrackets+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        int openBrackets = 0;
        int closeBrackets = 0;

        vector<string>answer;

        recursion(answer,n,openBrackets,closeBrackets,"");

        return answer;
        
    }
};