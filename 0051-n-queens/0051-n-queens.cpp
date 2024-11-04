class Solution {
private:
    void solve(int col,vector<vector<string>>&ans, vector<string>&temp,vector<int>&uD, vector<int>&lD, vector<int>&left, int n){
        if(col==n){
            ans.push_back(temp);
        }
        for(int row=0;row<n;row++){
            if(left[row]==0&&uD[row+col]==0&&lD[col-row+n-1]==0){
                left[row]=1;
                uD[row+col]=1;
                lD[col-row+n-1]=1;
                temp[row][col]='Q';
                solve(col+1,ans,temp,uD,lD,left,n);
                left[row]=0;
                uD[row+col]=0;
                lD[col-row+n-1]=0;
                temp[row][col]='.';                

            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<int>upperDiagonal(n*2-1,0);
        vector<int>lowerDiagonal(n*2-1,0);
        vector<int>left(n,0);
        string s(n,'.');
        vector<string>temp(n);
        for(int i=0;i<n;i++){
            temp[i]=s;
        }
        solve(0,ans,temp,upperDiagonal,lowerDiagonal,left,n);
        return ans;
    }
};