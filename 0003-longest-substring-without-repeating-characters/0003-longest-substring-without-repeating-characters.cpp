class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j,k;
        j=0,k=0;
        set<char> st;
        int cnt=0;

        for(int i=0;i<s.size();i++){
            while(st.find(s[i])!=st.end()){
                st.erase(s[j]);
                ++j;
            }

            st.insert(s[i]);
            cnt=max(cnt,i-j+1);

        }
        return cnt;
    }
};