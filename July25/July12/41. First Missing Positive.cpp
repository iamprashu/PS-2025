class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
        for(int i=0; i<n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                // agar value pos hai and n se small hai and agar value ko index mane to kya vo uski
                //actual jagah pe hai ya nahi
                //tabhi swap krunga
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return n+1;
        
    }
};