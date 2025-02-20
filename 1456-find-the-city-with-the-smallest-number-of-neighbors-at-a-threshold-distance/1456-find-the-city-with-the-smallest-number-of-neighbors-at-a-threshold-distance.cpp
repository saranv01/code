class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    unordered_map<int,int>mp;
    vector<vector<int>>dist(n,vector<int>(n,1e7));
    for(auto it:edges){
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    for(int i=0;i<n;i++){
        dist[i][i]=0;
    }
     for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]));
            }
        }  
     }
     for(int i=0;i<n;i++){
        int flg=0;
        for(int j=0;j<n;j++){
            if(dist[i][j]<=distanceThreshold&&i!=j){
                mp[i]++;
                mp[j]++;
            }
             if(i!=j&&dist[i][j]<=distanceThreshold){
                flg=1;
            }
        }
        if(flg==0)mp[i]=0;
     }
     
     vector<pair<int,int>>vec(mp.begin(),mp.end());
     sort(vec.begin(),vec.end(),[](const pair<int,int>&a, const pair<int,int>&b){
        if(a.second==b.second){
            return (a.first>b.first);
        }
        return a.second<b.second;
     });
    return vec[0].first;
    }
};