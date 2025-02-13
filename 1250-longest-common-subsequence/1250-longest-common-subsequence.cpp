class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
            vector<int>prev(text2.size()+1,0);
            vector<int>curr(text2.size()+1,0);
            int ans=0;
            for(int i=0;i<text1.length();i++){
                for(int j=0;j<text2.length();j++){
                    int pic=0;
                    if(text1[i]==text2[j]){
                        pic=1+prev[j];
                    }
                    int npic=max(0+prev[j+1],0+curr[j]);
                     curr[j+1]= max(pic,npic);
                     ans=max(ans,curr[j+1]);  
                }
                prev=curr;
            }
            return ans;
    }
};