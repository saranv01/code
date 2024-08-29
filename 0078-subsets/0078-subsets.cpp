class Solution {
public:
    void solve(vector<int>&nums,vector<int>&temp,vector<vector<int>>&ds,int pos){
        if(pos==nums.size()){
            ds.push_back(temp);
            return;
        }
        temp.push_back(nums[pos]);
        solve(nums,temp,ds,pos+1);
        temp.pop_back();
        solve(nums,temp,ds,pos+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> temp;
        solve(nums,temp, ds,0);
        return ds;
    }
};