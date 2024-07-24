class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>Dp(n,-1);
        Dp[0]=nums[0];
        if(n>1)
        Dp[1]=max(nums[1],Dp[0]);
        for(int i=2;i<n;i++){
            Dp[i]=max(Dp[i-2]+nums[i],Dp[i-1]);
        }

       return Dp[n-1];


    }
};