class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0){
            return "";
        }

        if(strs.size() == 1){
            return strs[0];
        }
        
        string assumption = strs[0];
        string answer="";

        int finalIndex = INT_MAX;

        for(int i=0; i<strs.size(); i++){
            string str = strs[i];

            if(str[0] != assumption[0]){
                return answer;
            }

            int currentIndex = -1;

            for(int i=0; i<str.size(); i++){

                if(assumption[i] != str[i]){
                    break;
                }else{
                    currentIndex++;
                }
            } 

            finalIndex = min( finalIndex, currentIndex); 
            cout<<finalIndex<<endl;
        }

       
        if(finalIndex == -1){
            return answer;
        }else{
            for(int i=0; i<=finalIndex; i++){
                answer.push_back(assumption[i]);
            }
        }

        return answer;
        
    }
};