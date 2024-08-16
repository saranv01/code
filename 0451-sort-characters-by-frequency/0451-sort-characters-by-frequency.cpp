class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char x:s){
            mp[x]++;
        }
        vector<pair<char,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](const auto& p1,const auto& p2){
            return p1.second>p2.second;
        });
        string res="";
        for(int i=0;i<vec.size();i++){
            res.append(vec[i].second,vec[i].first);
        }
        return res;

    }
};