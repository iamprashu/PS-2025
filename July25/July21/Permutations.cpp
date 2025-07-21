// leetcode 46: Permutations
class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int> > &ans){
        if(i>=nums.size()){
            ans.push_back(nums);
            return;
        }

        //it place pe sabko ek bar rakhna hai
        for(int j=i; j<nums.size();j++){
            swap(nums[i], nums[j]);
            solve(nums,i+1,ans);
            //backtrack jesa tha pahle wesa krdo
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        int i=0;
        solve(nums, i, ans);
        return ans;
    }
};