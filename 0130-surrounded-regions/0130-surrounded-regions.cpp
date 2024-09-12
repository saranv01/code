class Solution {
public:
    void dfs(vector<vector<char>>&visited,int i,int j){
        visited[i][j]='X';
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if (x >= 0 && x < visited.size() && y >= 0 && y < visited[0].size() && visited[x][y] == 'O') {
                dfs(visited, x, y);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<char>>visited(board.begin(),board.end());
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0||i==board.size()-1||j==0||j==board[0].size()-1)&& visited[i][j]=='O'){

                    dfs(visited,i,j);

                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(visited[i][j]=='O'){
                    board[i][j]='X';
                }
                if(visited[i][j]=='*'){
                    board[i][j]='O';                
                }
            }
        }
    }
};