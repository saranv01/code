class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            if(mp.find(num)==mp.end()){
                mp[num]++;
            }
            else{
                return num;
            }
        }
        return 0;
    }
};