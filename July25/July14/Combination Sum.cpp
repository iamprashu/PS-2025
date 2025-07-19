class Solution {
public:

    void helperRecur(int index,int target,vector<int>&candidates,vector<vector<int>>&answer,vector<int>&temp){
        
        if(index == candidates.size()){
            if(target == 0){
                answer.push_back(temp);                
            }
            return;
        }

        int currentElement = candidates[index];

        if(currentElement <= target){
            temp.push_back(currentElement);
            helperRecur(index,target-currentElement,candidates,answer,temp);
            temp.pop_back();
        } 

        helperRecur(index+1,target,candidates,answer,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> answer;
         vector<int>helperArray;
         helperRecur(0,target,candidates,answer,helperArray);

         return answer;
    }
};