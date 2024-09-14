class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=grid[0][0];
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        queue<pair<int,pair<int,int>>>q;
        q.push({dist[0][0],{0,0}});
        while(!q.empty()){
            int h=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<n && nx>=0 && ny<m && ny>=0 && h+grid[nx][ny]<dist[nx][ny]){
                    dist[nx][ny]=h+grid[nx][ny];
                    q.push({h+grid[nx][ny],{nx,ny}});
                }
            }
        }
        if(dist[n-1][m-1]<health)return true;
        return false;
    }
};