class Solution {
public:

    bool isValid(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int n, int m){
        if(row>=0&&col>=0&&row<n&&col<m&&vis[row][col]==0&&grid[row][col]!=0) return true;
        return false;
    }

    void getGold(int row,int col,int sum,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<int>& ans,vector<char>&ch,int n,int m){
                    ans.push_back(sum);
            for(auto c:ch){
                if(c=='d'&&isValid(row+1,col,vis,grid,n,m)){
                    vis[row+1][col]=1;
                    sum+=grid[row+1][col];
                    getGold(row+1,col,sum,grid,vis,ans,ch,n,m);
                    vis[row+1][col]=0;
                    sum-=grid[row+1][col];
                }
                else if(c=='l'&&isValid(row,col-1,vis,grid,n,m)){
                    vis[row][col-1]=1;
                    sum+=grid[row][col-1];
                    getGold(row,col-1,sum,grid,vis,ans,ch,n,m);
                    vis[row][col-1]=0;
                    sum-=grid[row][col-1];
                }
                else if(c=='r'&&isValid(row,col+1,vis,grid,n,m)){
                    vis[row][col+1]=1;
                    sum+=grid[row][col+1];
                    getGold(row,col+1,sum,grid,vis,ans,ch,n,m);
                    vis[row][col+1]=0;
                    sum-=grid[row][col+1];
                }
                else if(c=='u'&&isValid(row-1,col,vis,grid,n,m)){
                    vis[row-1][col]=1;
                    sum+=grid[row-1][col];
                    getGold(row-1,col,sum,grid,vis,ans,ch,n,m);
                    vis[row-1][col]=0;
                    sum-=grid[row-1][col];
                }
            

             
                }
            }
      

    

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int> ans;

        vector<char> ch={'d','l','r','u'};
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]!=0) flag=1;
            if(grid[i][j]!=0){
            vis[i][j]=1;
            getGold(i,j,grid[i][j],grid,vis,ans,ch,n,m);   
            vis[i][j]=0;             
            }

            }
        }

        if(flag==0) return 0;

        return *max_element(ans.begin(),ans.end());
    }
};