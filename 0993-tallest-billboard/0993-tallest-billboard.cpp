class Solution {
private:
    int solve(vector<int>&rods, int index, int difference,vector<vector<int>>&dp){
        if(index==rods.size())return difference==0?0:-1e9;
        if(dp[index][difference+5000]!=-1) return dp[index][difference+5000];
        int addToLeftSupport=rods[index]+solve(rods,index+1,difference+rods[index],dp);
        int addToRightSupport=solve(rods,index+1, difference-rods[index],dp);
        int addToNothing =solve(rods,index+1,difference,dp);
        return dp[index][difference+5000]=max(max(addToLeftSupport,addToRightSupport),addToNothing);
    }
public:
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>dp(20,vector<int>(100001,-1));
        return solve(rods, 0, 0,dp);
    }
};