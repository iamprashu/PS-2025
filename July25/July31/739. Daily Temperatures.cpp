class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i=0;
        int n = temperatures.size();
        stack<int>st;
        vector<int>answer(n,0);

        while(i<n){
        
            if(st.empty()){//agar stack khali h to only push
                st.push(i);
            }else if(temperatures[st.top()] < temperatures[i]){
                while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                    answer[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);

                //khatam hote hi top pe curent ko
            }else{
                st.push(i);
            }
            i++;
        }

        return answer;

    }
};