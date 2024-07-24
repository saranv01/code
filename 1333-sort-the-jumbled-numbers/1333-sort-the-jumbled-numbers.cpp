class Solution {
public:

    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<b.second;
    }

    int f(int x, unordered_map<int,int>mp){
        int ans=0;
        string s=to_string(x);

        int i=0;
        while(s[i]!='\0'){
            int n=(int)s[i]-'0';

            ans=10*ans+(mp[n]);
            i++;
        }
 
        return ans;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
       unordered_map<int,int> mp;
       vector<pair<int,int>>vecpr(nums.size());
       vector<int> result(nums.size());
       for(int i=0;i<mapping.size();i++){
            mp[i]=mapping[i];
       } 


       for(int i=0;i<nums.size();i++){
            vecpr[i].first=nums[i];
            vecpr[i].second=f(nums[i],mp);
       }
        sort(vecpr.begin(),vecpr.end(),comp);
        int i=0;
        for(auto x:vecpr) {
            result[i]=x.first;
            i++;
        }
            return result;
    }
};