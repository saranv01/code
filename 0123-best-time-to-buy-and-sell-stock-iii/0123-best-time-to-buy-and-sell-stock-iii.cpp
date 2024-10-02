class Solution {
public:
    int maxProfitHelper(int cur, int buy, int k,vector<int>&prices, vector<vector<vector<int>>>& dp){
        if(cur==prices.size()||k==0) return 0;
        if(dp[cur][buy][k]!=-1) return dp[cur][buy][k];
        int profit=0;

        if(buy){
            profit=max(maxProfitHelper(cur+1,0,k,prices,dp)-prices[cur],0+maxProfitHelper(cur+1,1,k,prices,dp));
        }
        else{
            profit=max(maxProfitHelper(cur+1,1,k-1,prices,dp)+prices[cur],maxProfitHelper(cur+1,0,k,prices,dp)+0);
        }

        return dp[cur][buy][k]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2,vector<int>(3,-1)));
        return maxProfitHelper(0,1,2,prices, dp);
    }
};