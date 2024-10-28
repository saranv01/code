class Solution {
public:
    void perm(vector<vector<int>>&ans,vector<int>&vis, vector<int>&nums, vector<int>&ds, int n){
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                ds.push_back(nums[i]);
                perm(ans,vis,nums,ds,n);
                ds.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>visited(n);
        vector<int>ds;
        for(int i=0;i<n;i++){
            visited[i]=0;
        }
        perm(ans, visited,nums,ds,n);
        return ans;
    }
};