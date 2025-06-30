class Solution {
public:
    void mapperFunction(string &str){
        char x = 'a';
        unordered_map<char,char>table;

        for(auto ch : str){
            if(table.find(ch) == table.end()){
                table[ch] = x;
                x++;
            }
        }

        //now its time to nomalize the string

        for(int i=0; i<str.size(); i++){
            str[i] = table[str[i]];
        }

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // step 1 normalize the pattern

        mapperFunction(pattern); //yaha pe patern normal ho gyi 

        for(auto st: words){
            mapperFunction(st);
        }

        //answer 
        vector<string>answer;

        for(auto st:words){
            string temp = st;
            mapperFunction(temp);

            if(temp==pattern){
                answer.push_back(st);
            }
        }

        return answer;
    }
};