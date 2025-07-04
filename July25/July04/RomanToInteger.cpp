class Solution {
public:
    
    int romanToInt(string s) {
        int digit=0;

        unordered_map<char,int>table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        int i=0;
        while(i<s.size()){

            if(s[i] == 'I' && i<s.size()-1){
                if(s[i+1] == 'V'){
                    digit += 4;
                    i+=2;
                }else if(s[i+1] == 'X'){
                    digit+=9;
                    i+=2;
                }else{
                    digit += 1;i++;
                }
            }else if(s[i] == 'X' && i<s.size()-1){
                if(s[i+1] == 'L'){
                    digit += 40;
                    i+=2;
                }else if(s[i+1] == 'C'){
                    digit += 90;
                    i+=2;
                }else{
                    digit+=10;i++;
                }
            }else if(s[i] == 'C' && i<s.size()-1){
                if(s[i+1] == 'D'){
                    digit += 400;
                    i+=2;
                }else if(s[i+1] == 'M'){
                    digit += 900;
                    i+=2;
                }else{
                    digit+=100;i++;
                }
            }else{
                digit += table[s[i]];
                i++;
            }
            
        }
        return digit;
    }
};