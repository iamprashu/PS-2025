// User function Template for C++

class Solution {
  public:
    void get(stack<int> &st, int x){
        
        if(st.empty()){
            st.push(x);
            return;
        }
        
        
        int top = st.top();
        st.pop();
        get(st, x);
        st.push(top);
        
    }
    stack<int> insertAtBottom(stack<int> st, int x) {
        get(st,x);
        
        return st ;
        
    }
};