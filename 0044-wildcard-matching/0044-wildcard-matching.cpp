class Solution {
public:
    bool solve(string& s, string& p, int spos, int ppos,vector<vector<bool>>&dp){
        //base condition
        if(spos==-1&&ppos==-1)return true;
        if(ppos==-1) return false;
        if(spos<=-1&&ppos>-1){
            while(ppos!=-1 &&p[ppos]=='*'){
                ppos--;
            }
            if(ppos==-1)return true;
            return false;
        }
if(dp[spos+1][ppos+1]!=1)return dp[spos+1][ppos+1];
        bool result=false;
        if(p[ppos]=='*'){
            result= (solve(s,p,spos-1,ppos,dp)||solve(s,p,spos,ppos-1,dp));
        }
        //what if letters

        if(s[spos]==p[ppos]) result=solve(s,p,spos-1,ppos-1,dp);
  
        if(p[ppos]=='?'){
            result= solve(s,p,spos-1,ppos-1,dp);
        }
        return dp[spos+1][ppos+1]= result;

    }
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp(s.size()+1,vector<bool>(p.size()+1,-1));
        return solve(s,p,s.size()-1,p.size()-1,dp);
    }
};