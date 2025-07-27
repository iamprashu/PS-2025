class Solution {
  public:
      void help(vector<int>& arr,vector<int>& answer,stack<int>& temp,int index){
          if(index < 0){
              return;
          }
          
          int element = arr[index];
          
          while(!temp.empty() && temp.top() <= element){
              temp.pop();
          }
          
          if(temp.empty()){
              answer[index] = -1;
          }else{
              answer[index] = temp.top();
          }
          temp.push(element);
          
          help(arr,answer,temp,index-1);
      }
    vector<int> nextLargerElement(vector<int>& arr) {
       vector<int>answer(arr.size(),-1);
       stack<int>temp;
       help(arr,answer,temp,arr.size()-1);
       return answer;
    }
};