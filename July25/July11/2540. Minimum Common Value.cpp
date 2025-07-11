class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a=0;
        int b=0;
        int answer = INT_MAX;

        while(a<nums1.size() && b<nums2.size()){
            if(nums1[a] == nums2[b]){
                answer = min(nums1[a],answer);
                a++;
                b++;
            }else if(nums1[a] < nums2[b]){
                a++;
            }else{
                b++;
            }
        }

        if(answer == INT_MAX){
            return -1;
        }

        return answer;
        
    }
};