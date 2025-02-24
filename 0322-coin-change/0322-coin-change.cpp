class Solution {
public:
    int solve(vector<int>&coins,int amount, int pos,vector<vector<int>>&dp){
        if(dp[amount][pos]!=-1){
            return dp[amount][pos];
        }

        if(pos==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }

        int pick=1e9;
        if(amount>=coins[pos]){
            pick=1+solve(coins,amount-coins[pos],pos,dp);
        }

        int notPick=1e9;
        notPick=0+solve(coins,amount,pos-1,dp);
        
        return dp[amount][pos]= min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(amount+1,vector<int>(coins.size(),-1));
        int ans= solve(coins,amount,coins.size()-1,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};