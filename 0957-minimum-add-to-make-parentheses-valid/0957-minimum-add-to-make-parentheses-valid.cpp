class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int cnt2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                 cnt++;
            }
            else{
                if(cnt>0)cnt--;
                else cnt2++;
            }
        }
        return cnt+cnt2;
    }
};