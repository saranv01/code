class Solution {
public:
    bool solve(vector<int>&nums,int pos,vector<int>&dp){
        if(dp[pos]!=-1)return dp[pos];
        if(pos>=nums.size()-1)return true;
        for(int i=1;i<=nums[pos];i++){
            if(solve(nums,pos+i,dp))return dp[pos]=1;
        }
        return dp[pos]=0;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(1e6,-1);
       return solve(nums,0,dp);
    }
};