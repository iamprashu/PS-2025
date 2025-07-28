class Solution {
public:
    int trap(vector<int>& height) {
        //using two pointer approach
        int n = height.size();
        int left = 0;
        int right = n-1;

        int max_l=INT_MIN;
        int max_r=INT_MIN;
        int answer=0;

        while(left<right){
            max_l = max(height[left],max_l);
            max_r = max(height[right],max_r);

            if(max_l < max_r){
                answer+= max_l - height[left];
                left++;
            }else{
                answer += max_r - height[right];
                right--;
            }
            
        }

        return answer;
        
        
    }
};