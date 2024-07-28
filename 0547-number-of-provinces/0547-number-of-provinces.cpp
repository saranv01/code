class Solution {
private:
    void dfs(int node,vector<int>&visited,vector<int>adjLis[]){
        visited[node]=1;
        for(auto x:adjLis[node]){
            if(!visited[x])
            dfs(x,visited,adjLis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<int> adjLis[v];
        int cnt=0;
        vector<int> visited(v,0);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1&&i!=j){
                    adjLis[i].push_back(j);
                    adjLis[j].push_back(i);
                }
            }
        }
        for(int i=0;i<v;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adjLis);
            }
        }
    return cnt;

        
    }
};