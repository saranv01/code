class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjList(n+1); //adjacency list
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //priority queue<weight,node>
        vector<int>dist(n+1,10e6);  //distances

        //making adjaceny list
        for(auto it:times){
            int u=it[0], v=it[1], wt=it[2];
            adjList[u].push_back({v,wt});
        }

        //marking the starting node's distance as 0
        dist[k]=0;

        //pushing the starting node to the pq
        pq.push({0,k});

        while(!pq.empty()){
            //extracting the q.top and poping the top
            int node=pq.top().second;
            int prevdist=pq.top().first;
            pq.pop();
            for(auto it:adjList[node]){
                if(it.second+prevdist<dist[it.first]){
                    dist[it.first]=it.second+prevdist;
                    pq.push({it.second+prevdist,it.first});
                }
            }

        }
            int maxtime=-1;
            for(int i=1;i<n+1;i++){
                if(dist[i]==10e6)return -1;
                else{
                    maxtime=max(dist[i],maxtime);
                }
            }
            return maxtime;
    }
};