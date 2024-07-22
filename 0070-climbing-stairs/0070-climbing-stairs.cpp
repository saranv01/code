class Solution {
public:

    int findStep(int n,vector<int>&Dp){
        if(n<0){
            return 0;
        }
        if(n==0) return 1;
        if(Dp[n]==-1){
         Dp[n]= findStep(n-1,Dp)+findStep(n-2,Dp);
             
        }
        
        return Dp[n];
    }

    int climbStairs(int n) {
        vector <int> Dp(n+1,-1);
        Dp[0]=1;
        return findStep(n,Dp);
        
    }
};