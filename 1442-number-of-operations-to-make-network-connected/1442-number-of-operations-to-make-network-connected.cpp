class DisjointSet{
    public:
    int size;
    vector<int>height;
    vector<int>parent;
    DisjointSet(int n):size(n){
        height.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int findParent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findParent(parent[x]);
    }
    void addNodes(int u, int v){
        int pu =findParent(u);
        int pv=findParent(v);
        if(height[pu]>height[pv]){
            parent[pv]=pu;
            height[pu]++;
        }
        else{
            parent[pu]=pv;
            height[pv]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int OverallCablesRequired=n-1;
        int numberOfNetworks=0;
        if(connections.size()<OverallCablesRequired)return -1;
        for(int i=0;i<connections.size();i++){
            ds.addNodes(connections[i][0],connections[i][1]);
        }
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)numberOfNetworks++;
        }
        return numberOfNetworks-1;
    }
};