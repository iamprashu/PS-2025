class Solution {
public:
    string simplifyPath(string path) {
        int size = path.size();
        stack<string>st;
        int i=0;

        while(i<size){
            // get to the dir or file name only skip all / 

            while(path[i] == '/' && i<size)i++;

            string x="";//to make current word

            while(path[i] != '/' &&  i<size){
                x += path[i];
                i++;
            }
            //ab word ban gay ahoga to stack me push krna h

            if( x == ".."){
               if(!st.empty()){
                    st.pop();
                }
            }else if(!x.empty() && x != "."){
                st.push(x);
            }
        }

        // now i have all the Dirs in a stack need to make a string of them

        string answer = "";

        while(!st.empty()){
            string last = st.top();
            answer = "/" + last + answer;
            st.pop();
        }

        return answer.empty() ? "/" : answer;
    }
};