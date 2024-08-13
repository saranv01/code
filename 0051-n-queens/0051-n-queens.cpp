class Solution {
public:
    bool isValid(int row,int col,vector<string>&board){
        if(col>=board.size())return false;
        int r=row;
        int c=col;
        while(row>=0&&col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }

        row=r;
        col=c;
        while(row<board.size()&&col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        row=r;
        col=c;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans){
        if(col==board.size()){
            ans.push_back(board);
        }
        for(int row=0;row<board.size();row++){
            if(isValid(row,col,board)){
                board[row][col]='Q';
                solve(col+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string>board(n,s);
        solve(0,board,ans);
        return ans;
    }
};