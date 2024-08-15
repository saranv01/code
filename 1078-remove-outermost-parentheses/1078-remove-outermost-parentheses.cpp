class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ss="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
                if(cnt!=1) ss+=s[i];
            }
            if(s[i]==')'){
                cnt--;
                if(cnt!=0) ss+=s[i];
            }
        }
        return ss;
    }
};