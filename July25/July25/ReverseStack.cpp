// User function Template for C++

class Solution {
  public:
    void PushAtBottom(stack<int> &st, int x){
        
        if(st.empty()){
            st.push(x);
            return;
        }
        
        
        int top = st.top();
        st.pop();
        PushAtBottom(st, x);
        st.push(top);
        
    }
    void Reverse(stack<int> &st) {
        if(st.empty()){
            return;
        }
        int top = st.top();
        st.pop();
        Reverse(st);
        PushAtBottom(st,top);
    }
};