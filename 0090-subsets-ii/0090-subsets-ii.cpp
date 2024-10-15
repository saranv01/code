class Solution {
public:
    void helper(vector<int>&nums, int pos, vector<int>&temp, vector<vector<int>>&result, int n){
        result.push_back(temp);
        for(int i=pos;i<n;i++){
            if(i!=pos&&nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            helper(nums,i+1,temp,result,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int>temp;
     sort(nums.begin(),nums.end());
     vector<vector<int>>ans; 
     helper(nums,0,temp,ans,nums.size());
     return ans;   
    }
};