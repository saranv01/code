class Solution {
public:
    int scoreOfString(string s) {
        int i,j;
        i=0;
        j=1;
        int ans=0;
        while(j<s.size()){
            ans+=abs((s[i])-(s[j]));
            i++;
            j++;
        }
        return ans;
    }
};