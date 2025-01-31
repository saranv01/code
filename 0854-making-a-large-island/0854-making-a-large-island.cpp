class DisjoinedSet{
    vector<int>parent;

public:
    vector<int>height;
    DisjoinedSet(int n){
        height.resize(n+1,1);
        parent.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int n){
        if(n==parent[n]){
            return n;
        }
        return parent[n]=findParent(parent[n]);
    }
    bool isConnected(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv){
            return true;
        }
        return false;
    }
    void unionByHeight(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(height[pu]<height[pv]){
            parent[pu]=pv;
            height[pv]=height[pv]+height[pu];
        }
        else{
            parent[pv]=pu;
            height[pu]=height[pv]+height[pu];
        }
        return;     
    }
    
};


int getNumForIndex(int i, int j, int n){
    return (i*n)+j;
}

int delx[4]={0,1,0,-1};
int dely[4]={1,0,-1,0};



void dfsAndUnion(int i, int j, vector<vector<int>>&visited, vector<vector<int>>&matrix,DisjoinedSet& ds){
    if(visited[i][j]==1)return;

    visited[i][j]=1;
    int u=ds.findParent(getNumForIndex(i,j,matrix[0].size()));
    for(int k=0;k<4;k++){
        int newx=i+delx[k];
        int newy=j+dely[k];
        if(newx>=0&&newy>=0&&newx<matrix.size()&&newy<matrix[0].size()&&matrix[newx][newy]==1&&visited[newx][newy]==0){
            int v=getNumForIndex(newx,newy,matrix[0].size());
            ds.unionByHeight(u,v);
            dfsAndUnion(newx,newy,visited,matrix,ds);
        }
    }
    return;
}


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        //making the disjoined set;
        DisjoinedSet ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&visited[i][j]==0){
                    dfsAndUnion(i,j,visited,grid,ds);
                }
            }
        }
        set<int>st;
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    for(int k=0;k<4;k++){
                        int newx=i+delx[k];
                        int newy=j+dely[k];
                        if(newx>=0&&newy>=0&&newx<n&&newy<m&&grid[newx][newy]==1){
                            int v=getNumForIndex(newx,newy,grid[0].size());
                            st.insert(ds.findParent(v));
                        }
                    }
                    int tempArea=0;
                    for(auto it:st){
                        tempArea+=ds.height[it];
                        st.erase(it);
                    }
                 
                    maxArea=max(maxArea,tempArea+1);
                }
            }
        }
        if(maxArea==0){
            return n*m;
        }
        return maxArea;   
    }
};