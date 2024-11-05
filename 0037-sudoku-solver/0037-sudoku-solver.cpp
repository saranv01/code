class Solution {
private:
    bool isValid(int row, int col, char n,vector<vector<char>>&board){
        for(int i=0;i<9;i++){
            if(board[i][col]==n)return false;
            if(board[row][i]==n)return false;
            if(board[(row/3)*3+i/3][(col/3)*3+i%3]==n)return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
         int i,j;
        for(i=0;i<board.size();i++){
            for(j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(i,j,c,board)){
                            board[i][j]=c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }
                            
                        }
                       
                    } 
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};