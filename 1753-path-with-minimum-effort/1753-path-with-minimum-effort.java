class Pair{
    int distance;
    int i;
    int j;
    public Pair(int distance, int i, int j){
        this.distance=distance;
        this.i=i;
        this.j=j;
    }
}

class Solution {
    public int minimumEffortPath(int[][] heights) {
        
        int adj[][]=heights;
        int n=heights.length;
        int m=heights[0].length;
        int distances[][]=new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                distances[i][j]=Integer.MAX_VALUE;
            }
        }
        distances[0][0]=0;
        Queue<Pair> q =new LinkedList<> ();
        q.add(new Pair(0,0,0));
        while(!q.isEmpty()){
            int dist=q.peek().distance;
            int ii=q.peek().i;
            int jj=q.peek().j;
            q.remove();
            int delx[]={0,0,1,-1};
            int dely[]={-1,1,0,0};
            for(int k=0;k<4;k++){
                int newX=ii+delx[k];
                int newY=jj+dely[k];
                if(newX>=0&&newY>=0&&newX<n&&newY<m){
                int effort = Math.max(dist, Math.abs(heights[newX][newY] - heights[ii][jj]));
                    if(effort<distances[newX][newY]){
                        distances[newX][newY]=effort;
                        q.add(new Pair(effort,newX,newY));
                    }
                }
            }

        }
        return distances[n-1][m-1];
    }
}