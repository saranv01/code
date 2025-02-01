class DisjointSet{
    public:
        vector<int>parent;
        vector<int>size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(parent[x]==x)return x;
        return findParent(parent[x]);
    }
    void unionBySize(int u, int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        else if(size[pv]>size[pu]) parent[pu]=pv;
        else parent[pv]=pu;
        return;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int>mp;
        DisjointSet ds(accounts.size());
        vector<vector<string>>ans;
        for(int i=0;i<accounts.size();i++){
            int j=0;
            for(auto it:accounts[i]){
                if(j==0){
                    j++;
                    continue;
                }
                if(mp.find(it)==mp.end()){
                    mp[it]=i;
                }
                else{
                    ds.unionBySize(mp[it],i);
                }
            }
        }
        for(int i=0;i<accounts.size();i++){
            vector<string>temp;
            for(auto it:mp){
                if(i==ds.findParent(mp[it.first])){
                    temp.push_back(it.first);
                }
            }
            if(temp.size()!=0){
                sort(temp.begin(),temp.end());
                temp.insert(temp.begin(),accounts[i][0]);
                ans.push_back(temp);                
            }
        }
        return ans;
    }
};