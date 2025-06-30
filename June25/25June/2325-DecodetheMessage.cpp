class Solution {
public:
    string decodeMessage(string key, string message) {
        //steps pahle mapping banani hogi
        unordered_map<char,char>table;
        char spacechar = ' ';
        table[spacechar] = spacechar;
        char alphabet = 'a';
        int index = 0;

        while(alphabet <= 'z' && index < key.size() ){
            char currentKeyChar = key[index];

            if(table.find(currentKeyChar) != table.end()){
                index++;
            }else{
                table[currentKeyChar] = alphabet;
                index++;
                alphabet++;
            }
        }

        string answer="";

        for(int i=0; i<message.size(); i++){
            char messageChar = message[i];
            char tableChar = table[messageChar];

            answer.push_back(tableChar);
        }

        return answer;
    }
};