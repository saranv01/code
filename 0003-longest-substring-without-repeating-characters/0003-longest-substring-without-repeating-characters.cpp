class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int l,res;
        l=res=0;
        for(int r=0;r<s.size();r++){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l)
                l=mp[s[r]]+1;
                
            }
            mp[s[r]]=r;

            res=max(res,r-l+1);

        }

        return res;
    }
};