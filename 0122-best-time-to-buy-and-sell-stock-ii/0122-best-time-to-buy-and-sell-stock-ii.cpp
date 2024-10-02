class Solution {
public:
    int recMax(int cur, int buy, vector<int>&prices,vector<vector<int>>&dp){
        if(cur==prices.size())
        return 0;
        if(dp[cur][buy]!=-1)return dp[cur][buy];
        int profit=0;
        if(buy){
            profit=max(recMax(cur+1,0,prices,dp)-prices[cur], 0+recMax(cur+1,1,prices,dp));
        }
        else{
            profit=max(prices[cur]+recMax(cur+1,1,prices,dp),recMax(cur+1,0,prices,dp)+0);
        }
        return dp[cur][buy] =profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return recMax(0,1,prices,dp);
    }
};