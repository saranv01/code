class Solution {
public:
    void fF(vector<vector<int>>&pix,int sr, int sc, int color,int valid){
        if(pix[sr][sc]!=valid||pix[sr][sc]==color){
            return;
        }
        pix[sr][sc]=color;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int i=0;i<4;i++){
            int x =sr+dx[i];
            int y =sc+dy[i];
            if(x<pix.size()&&x>=0 && y<pix[0].size()&&y>=0 && pix[x][y]==valid){
                fF(pix,x,y,color,valid);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>pix(image.begin(),image.end());
        int valid=image[sr][sc];
        fF(pix,sr,sc,color,valid);
        return pix;
    }
};