class Solution {
public:
    int lcs(string& t1, string& t2, int l1, int l2,vector<vector<int>>&dp){
        if(l1==-1||l2==-1) return 0;
        if(dp[l1+1][l2+1]!=-1)return dp[l1+1][l2+1];
        int pic=0;
        if(t1[l1]==t2[l2]){
           pic=1+lcs(t1,t2,l1-1,l2-1,dp);
        }
        int npic=max((0+lcs(t1,t2,l1-1,l2,dp)),(0+lcs(t1,t2,l1,l2-1,dp)));
        return dp[l1+1][l2+1]= max(pic,npic);
    }
    int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
            return lcs(text1,text2,text1.length()-1,text2.length()-1,dp);
    }
};