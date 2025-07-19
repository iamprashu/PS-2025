class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //solving usin parallel run
        int p1 = m;
        int p2 = 0;

        while(p2<nums2.size()){
            nums1[p1] = nums2[p2];
            p1++;
            p2++;
        }

        sort(nums1.begin(),nums1.end());


        
    }
};