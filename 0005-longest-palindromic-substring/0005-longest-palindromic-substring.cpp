class Solution {
public:
    string findPalindrome(int l,int r,string s){
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
 
    string longestPalindrome(string s) {
        if(s.size()<=1)return s;
        string ans="";
        for(int i=0;i<s.size();i++){
            string odd=findPalindrome(i,i,s);
            string even=findPalindrome(i,i+1,s);
            if(odd.length()>ans.length()) ans=odd;
            if(even.length()>ans.length()) ans=even;
        }
        return ans;
    }
};