class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int serverCount=0;
        vector<pair<int,int>>grids;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)grids.push_back({i,j});
            }
        }
        for(int k=0;k<grids.size();k++){

        int i=grids[k].first;
        int j=grids[k].second;
                bool serverNotFound=true;
                //upper
                int nx=i-1;
                int ny=j;
                while(!(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size())){
                    if(grid[i][j]==1&&grid[nx--][ny]==1){
                        serverNotFound=false;
                        break;
                  
                    }
                }
                //right
                    if(!serverNotFound){
                        serverCount++;
                        continue;
                     
                    }
                nx=i;
                ny=j+1;
                while(!(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size())){
                    if(!serverNotFound){
                        break;
                    }
                    if(grid[i][j]==1&&grid[nx][ny++]==1){
                        serverNotFound=false;
                        break;
                    }
                     
                }
                    if(!serverNotFound){
                        serverCount++;
                        continue;
                    }
                //down
                nx=i+1;
                ny=j;
                while(!(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size())){
                    if(!serverNotFound){
                        break;
                    }
                    if(grid[i][j]==1&&grid[nx++][ny]==1){
                        serverNotFound=false;
                        break;
                    }
                                   cout<<"c"<<endl;
                }
                    if(!serverNotFound){
                        serverCount++;
                        continue;
                    }
                //left
                nx=i;
                ny=j-1;
                while(!(nx<0||ny<0||nx>=grid.size()||ny>=grid[0].size())){
                    if(!serverNotFound){
                        break;
                    }
                    if(grid[i][j]==1&&grid[nx][ny--]==1){
                        serverNotFound=false;
                        break;
                    }

                }
  
                    if(!serverNotFound){
                        serverCount++;

                    }
                      
    }
        return serverCount;
    }
};