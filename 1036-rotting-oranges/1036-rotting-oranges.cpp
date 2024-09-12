class Solution {
private:
    int rotOrange(vector<int>delx,vector<int>dely,vector<vector<int>>&visited,int& rottenOranges,queue<pair<pair<int,int>,int>>q,int m, int n){
        int time=0;
        while(!q.empty()){
            int f=q.front().first.first;
            int s=q.front().first.second;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                    int x=f+delx[i];
                    int y=s+dely[i];
                    int temp=t;
                    if(x<m&&x>=0 && y<n&&y>=0 &&visited[x][y]==1 ){
                        temp++;
                        time=max(time,temp);
                        rottenOranges++;
                        visited[x][y]=2;
                        q.push({{x,y},temp});
                    }
               }
        }    
        return time;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n));
        int initialFreshOrange=0;
        int rottenOranges=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)initialFreshOrange++;
                if(grid[i][j]==2)q.push({{i,j},0});
                visited[i][j]=grid[i][j];
            }
        }
        vector<int>delx={0, 0, 1, -1};
        vector<int>dely={1, -1, 0, 0};

        int time= rotOrange(delx,dely,visited,rottenOranges,q,m,n);
        return (initialFreshOrange==rottenOranges)?time:-1;




    }
};