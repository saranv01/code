class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int n=grid.size();
        int m=grid[0].size();
        int oranges=0;
        int rottenOranges=0;
        int days=0;

        queue<pair<int,int>>rotten;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0) oranges++;
                if(grid[i][j]==2){
                    rotten.push({i,j});
                }
            }
        }

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!rotten.empty()){
        int k=rotten.size();
        rottenOranges+=k;
        while(k--){
         
          
            int x=rotten.front().first,y=rotten.front().second;
            rotten.pop();
            for(int i=0;i<4;i++){
            
                    int ny=y+dy[i],nx=x+dx[i];
                    if(ny<0||nx<0||nx>n-1||ny>m-1||grid[nx][ny]!=1) continue;
                    rotten.push({nx,ny});
                    grid[nx][ny]=2;
   
            }
        }
        if(!rotten.empty()) days++;
        }

        if(rottenOranges==oranges) return days;
        return -1;


        
    }
};