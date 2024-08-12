class Solution {
public:
    void genSubset(vector<int>&nums,int n,int ind, vector<int>&ds,vector<vector<int>>&ans){

        if(ind==n){
            ans.push_back(ds);
            return;
        }

        ds.push_back(nums[ind]);
        genSubset(nums,n,ind+1,ds,ans);
        ds.pop_back();
        genSubset(nums,n,ind+1,ds,ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n =nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        genSubset(nums,n,0,ds,ans);
        return ans;
    }
};