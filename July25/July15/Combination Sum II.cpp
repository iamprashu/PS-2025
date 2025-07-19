class Solution {
public:
    void solve(int start, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& answer) {
        if(target == 0) {
            answer.push_back(temp);
            return;
        }

        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(i+1, target - candidates[i], candidates, temp, answer);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> temp;
        solve(0, target, candidates, temp, answer);
        return answer;
    }
};
