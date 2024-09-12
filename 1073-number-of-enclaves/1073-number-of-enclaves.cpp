class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==1&&vis[nx][ny]==0){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    ans++;
                }
            }
        } 
        return ans;
    }
};