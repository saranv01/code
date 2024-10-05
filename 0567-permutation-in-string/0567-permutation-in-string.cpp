class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        unordered_map<char,int>s1mp;
        unordered_map<char,int>s2mp;
        for(auto it:s1){
            s1mp[it]++;
        }
        for(int i=0;i<s1.size();i++){
            s2mp[s2[i]]++;
        }
        if(s1mp==s2mp)return true;

        for(int i=s1.size();i<s2.size();i++){
            s2mp[s2[i]]++;
            s2mp[s2[i-s1.length()]]--;
            if(s2mp[s2[i-s1.length()]]==0){
                s2mp.erase(s2[i-s1.length()]);
            }
            if(s1mp==s2mp)return true;
        }
        return false;
    }
};