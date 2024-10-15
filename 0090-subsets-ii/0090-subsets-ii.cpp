class Solution {
public:
    void helper(vector<int>&nums, int pos, vector<int>&temp, set<vector<int>>&result, int n){
        if(pos==n){
            sort(temp.begin(),temp.end());
            result.insert(temp);
            return;
        }
        temp.push_back(nums[pos]);
        helper(nums,pos+1,temp,result,n);
        temp.pop_back();
        helper(nums,pos+1,temp,result,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int>temp;
    sort(nums.begin(),nums.end());
     set<vector<int>>result;
     helper(nums,0,temp,result,nums.size());
     vector<vector<int>>ans(result.begin(),result.end()); 
     return ans;   
    }
};