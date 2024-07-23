class Solution {
public:


       static bool comp(pair<int,int>a,pair<int,int>b){
            if(a.second==b.second){
                return a.first>b.first;
            }
            return a.second<b.second;
        }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<pair<int,int>>vec(mp.begin(),mp.end());

        sort(vec.begin(),vec.end(),comp);

        vector<int>ans(nums.size());

int j=0;
        for(int i=0;i<vec.size();i++){
            while(mp[vec[i].first]--){
                   ans[j]=vec[i].first;
                   j++;
            }
         
        }
        return ans;
        
    }
};