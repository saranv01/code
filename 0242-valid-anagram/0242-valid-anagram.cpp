class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t)return true;
        // return false;

        unordered_map<char,int>mp;
        for(char x: s) mp[x]++;
        for(char x: t) mp[x]--;
        for(auto x: mp) if(x.second>0)return false;
        return true;
    }
};