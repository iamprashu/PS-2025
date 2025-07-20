class Solution {
public:
    void Concor(vector<int>&nums,int start,int end,int mid){
        int leftSize = mid-start+1;
        int rightSize = end - mid;

        vector<int>left(leftSize,0);
        vector<int>right(rightSize,0);

        int index = start;

        for(int i=0; i<leftSize; i++){
            left[i] = nums[index];
            index++;
        }

        index = mid+1;
        for(int j=0; j<rightSize; j++){
            right[j] = nums[index];
            index++;
        }

        //merging

        int i=0; 
        int j=0;
        int mainIndex = start;

        while(i<leftSize && j<rightSize){

            if(left[i] < right[j]){
                nums[mainIndex] = left[i];
                i++;
                mainIndex++;
            }else{
                nums[mainIndex] = right[j];
                j++;
                mainIndex++;
            }
        }

        while(i<leftSize){
            nums[mainIndex] = left[i];
            i++;
            mainIndex++;
        }

         while(j<rightSize){
            nums[mainIndex] = right[j];
            j++;
            mainIndex++;
        }


    }
    void Devide(vector<int>&nums,int start,int end){
        if(start >= end){
            //means single element aa gya hoga
            return;
        }

        //middle nikalo
        int mid = (start+end)/2;

        //pahle left ko 
        Devide(nums,start,mid);
        //phir right ko
        Devide(nums,mid+1,end);

        Concor(nums,start,end,mid);


    }
    vector<int> sortArray(vector<int>& nums) {
        //using merge sort D&C
        int start=0;
        int end = nums.size()-1;
        Devide(nums,start,end);

        return nums;
        
    }
};