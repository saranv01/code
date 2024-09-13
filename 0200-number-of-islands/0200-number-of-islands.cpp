class Solution {
public:
    void dfs(vector<vector<char>>& vis,vector<vector<char>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]='2';
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        for(int x=0;x<4;x++){
            int newX=i+dx[x];
            int newY=j+dy[x];

            if(newX<n && newX>=0 && newY<m && newY>=0 && vis[newX][newY]=='1'){
                dfs(vis,grid,newX,newY);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        vector<vector<char>> vis(grid.begin(),grid.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]=='1'){
                    count++;
                    dfs(vis,grid,i,j);
                }
            }
        }
        return count;
    }
};