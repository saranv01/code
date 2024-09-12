class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>performed(mat.begin(),mat.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int level=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x1=x+dx[i];
                int y1=y+dy[i];
                if(x1<n && x1>=0 && y1<m && y1>=0 && performed[x1][y1]==1){
                    performed[x1][y1]=level+1+1;
                    q.push({{x1,y1},level+1});
                }    
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    performed[i][j]=0;
                }
                else{
                    performed[i][j]--;
                }
            }
        }
        return performed;
    }
};