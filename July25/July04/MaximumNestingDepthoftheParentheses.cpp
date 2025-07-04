class Solution {
public:
    int maxDepth(string s) {

        int maxDepth = 0;
        int tempCount = 0;
        for(char x:s){
           switch(x){
            case '(':
                    tempCount++;
                    maxDepth = tempCount > maxDepth ? tempCount : maxDepth;
                    break;
            case ')':
                    tempCount--;
                    break;
           }
        }

        return maxDepth;
        
    }
};