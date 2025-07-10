class Solution {
public:
    void getAnswer(vector<int> &arr, int index,vector<vector<int>> &answer,vector<int>temp){
        //base case
        if(index == arr.size()){
            answer.push_back(temp);
            return;
        }

        //current Elemet
        int currentElement = arr[index];
        // vector<int>x;
        // x.push_back(currentElement);
        // answer.push_back(x);
        temp.push_back(currentElement);
        getAnswer(arr,index+1,answer,temp);
        temp.pop_back();
        getAnswer(arr,index+1,answer,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
        int index = 0;
        vector<int>temp = {};
        getAnswer(nums,index,answer,temp);
        return answer;
    }
};