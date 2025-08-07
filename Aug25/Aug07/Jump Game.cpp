class Solution {
public:
    bool canJump(vector<int>& nums) {
        //har iteration me bas max nikao aur jump krk dekho4
        int maxJump=0;

        for(int i=0; i <= maxJump; i++){
            maxJump = max(maxJump,nums[i] + i);

            if(maxJump >= nums.size()-1) return true;
        }
        return false;
    }
};