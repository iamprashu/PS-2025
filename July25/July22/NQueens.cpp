class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col, int n) {
       
       //as current row se nieche chek nahi hoga qki empty hai to 3 direction hai
       // 1. UP then Right Diagonali up, then left Diagonal Up

       // up direction check col same rega row less hogi
       for(int i = row - 1; i>=0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
       }

       //left diagonal up yaha pe row bhi decrease ho rha and col bhi

       for(int i=row-1,  j=col-1; (i>=0 && j>=0); i--,j-- ){
            if(board[i][j] == 'Q'){
                return false;
            }
       }
        // right diagonal up
        for(int i=row-1,  j=col+1; (i>=0 && j<n); i--,j++ ){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void solve(int row, vector<string> &board, vector<vector<string>> &res, int n) {
        if(row == n){
            res.push_back(board);
        }

        for(int col=0; col < n; col++){
            if(isSafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(row+1,board,res,n);
                board[row][col] = '.'; // taki next try kr sake 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        solve(0, board, res, n);
        return res;
    }
};
