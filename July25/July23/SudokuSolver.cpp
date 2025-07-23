class Solution {
public:

    bool checkSafe(vector<vector<char>>& board,int row,int col,char x){
        //check row Wise
        for(int i=0; i<9; i++){
            if(board[i][col] == x){
                return false;
            }
        }

        for(int i=0; i<9; i++){
            if(board[row][i] == x){
                return false;
            }
        }

        //check box
        int sr = (row/3) * 3;
        int sc = (col/3) *3;

        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if(board[i][j] == x){
                    return false;
                }
            }
        }


        return true;
    }
    void helper(vector<vector<char>>& board,int row,int col,bool &solved){
        //for each cell will call recurssion
        //base case hoga agar row == 9  ho gyi a & coll ya phir row == 9
        if(row == 9){
            solved = true;
            return;
        }

        if(solved) return;

        //recursion ke liye qki har next column k loye recursion call kr rha hu
        int nextRow = row;
        int nextCol = col + 1; // taki next call me isi pe na aaye 

        //check ki row to change nahi krni
        if(col+1 ==  9){ // means next out of bound hai 
            nextRow = row + 1;
            nextCol = 0;
        }

        //agar current place pe element hai to next call kro
        if(board[row][col] != '.'){
            helper(board,nextRow,nextCol,solved);
            return;
        }


        for(char x='1'; x<= '9'; x++){
            //check ki place krna safe hai ya nahi
            if(checkSafe(board,row,col,x)){
                board[row][col] = x;
                helper(board,nextRow,nextCol,solved);
                if (solved) return;
                //backtracking
                board[row][col] = '.';
            }
        }

    }
    void solveSudoku(vector<vector<char>>& board) {
        bool solved = false;

        helper(board,0,0,solved);
    }
};