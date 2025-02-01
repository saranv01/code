class Solution {
private:
    int solve(vector<int>&rods, int index, int difference,vector<vector<int>>&dp){

        if(index==rods.size()){
            return difference==0?0:-5000;
        }
        if(dp[index][difference+5000]!=-1){
            return dp[index][difference+5000];
        }
        //current index value is added
        int addToLeftSupport=rods[index]+solve(rods,index+1,difference+rods[index],dp);
        cout<<addToLeftSupport<<endl;
        //current index value is subtracted (this is where the function ends by finding value, coz the diff should be 0)
        int addToRightSupport=solve(rods,index+1, difference-rods[index],dp);

        //doing nothing here
        int addToNothing =solve(rods,index+1,difference,dp);


        return dp[index][difference+5000]=max(max(addToLeftSupport,addToRightSupport),addToNothing);
    }


public:
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>>dp(20,vector<int>(100001,-1));
        return solve(rods, 0, 0,dp);
    }
};