class Solution {
public:
    int findMax(vector<int>&ballons,int strt, int end,vector<vector<int>>&dp){
        if(dp[strt+1][end+1]!=-1)return dp[strt+1][end+1];
        if(strt>end)return 0;
        int Maxi=INT_MIN;
        int l,r;
        l=r=1;
        if(strt>0)l=ballons[strt-1];
        if(end<ballons.size()-1)r=ballons[end+1];
        for(int k=strt;k<=end;k++){
            int ans= l*ballons[k]*r + findMax(ballons,strt,k-1,dp) + findMax(ballons,k+1,end,dp);
            if(ans>Maxi){
                Maxi=ans;
            }
        }
        return dp[strt+1][end+1]=Maxi;
    }
    int maxCoins(vector<int>& nums) { 
        vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        return findMax(nums,0,nums.size()-1,dp);
    }
};