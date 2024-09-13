class Solution {
public:

    void dfs(int node,vector<int>& e, vector<int>& d,vector<int>&vis,int n1){
            vis[node]=1;
            d[node]=n1;
            if(e[node]!=-1&&vis[e[node]]==0){

                dfs(e[node],e,d,vis,n1+1);
            }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
            vector<int>dist1(edges.size(),-1);
            vector<int>dist2(edges.size(),-1);
            vector<int>vis1(edges.size(),0);
            vector<int>vis2(edges.size(),0);
            dist1[node1]=0;
            dist2[node2]=0;     
            dfs(node1,edges,dist1,vis1,0);
            
            dfs(node2,edges,dist2,vis2,0);
            int ans=-1;
            int mini=INT_MAX;
            for(int i=0;i<edges.size();i++){
                if(dist1[i]>=0&&dist2[i]>=0)
                if(max(dist1[i],dist2[i])<mini){
                    mini=max(dist1[i],dist2[i]);
                    ans=i;
                }
            }
            return ans;

    }
};