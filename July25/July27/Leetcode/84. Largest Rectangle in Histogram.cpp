class Solution {
public:
    vector<int>SER(vector<int>& heights){
        int n = heights.size();
        vector<int>answer(n,0);
        stack<int>t;

        for(int i=n-1; i>=0; i--){
            int currentElement = heights[i];

            while(!t.empty() && heights[t.top()] >= currentElement){
                t.pop();
            }

            if(t.empty()){
                answer[i] = n;
            }else{
                answer[i] = t.top();
            }
            t.push(i);
        }
        return answer;
    }

    vector<int>SEL(vector<int>& heights){
        int n = heights.size();
        vector<int>answer(n,0);
        stack<int>t;

        for(int i=0; i<n; i++){
            int currentElement = heights[i];

            while(!t.empty() && heights[t.top()] >= currentElement){
                t.pop();
            }

            if(t.empty()){
                answer[i] = -1;
            }else{
                answer[i] = t.top();
            }
            t.push(i);
        }
        return answer;
    }
    int largestRectangleArea(vector<int>& heights) {
        //approach get smaller right get smaller left getarea
        vector<int>leftSmaller = SEL(heights);
        vector<int>rightSmaller = SER(heights);
        int answer = INT_MIN;

        for(int i=0; i<heights.size(); i++){
            int area = heights[i] * (rightSmaller[i] - leftSmaller[i] - 1);

            answer=(area > answer)?area:answer; // store and compute
        }

        return answer;
        
    }
};