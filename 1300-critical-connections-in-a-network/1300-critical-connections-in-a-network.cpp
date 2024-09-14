class Solution {
private: 
    int timer=1;
    void dfs(vector<int>& vis,int par,int node,vector<vector<int>>&adj,vector<int>&low,vector<int>&tin,vector<vector<int>>&ans){
        vis[node]=1;
        low[node]=tin[node]=timer;
        timer++;
        for(auto it:adj[node]){
                if(it==par){
                  continue;   
                }
            if(vis[it]==0){
                dfs(vis,node,it,adj,low,tin,ans);
                low[node]=min(low[it],low[node]);
                    if(tin[node]<low[it]){
               ans.push_back({it,node});
                    }
            }
            else{
                        low[node]=min(low[it],low[node]);  
            }
        }
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<int>visited(n,0);
        vector<int>low(n);
        vector<vector<int>>ans;
        vector<int>tin(n);
            for(auto it:connections){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }

        
        dfs(visited,-1,0,adj,low,tin,ans);
        return ans;
    }
};