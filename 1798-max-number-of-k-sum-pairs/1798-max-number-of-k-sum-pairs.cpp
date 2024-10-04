class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }   
        for(int i=0;i<nums.size();i++){

            if(mp.find(k-nums[i])!=mp.end()&&mp[k-nums[i]]>0&&mp[nums[i]]>0){
                if(k-nums[i]==nums[i]){
                    if(mp[nums[i]]>=2){
                        count++;
                        mp[nums[i]]--;
                        mp[nums[i]]--;
                    }

                }
                else{
                    count++;
                    mp[k-nums[i]]--;
                    mp[nums[i]]--;
                }
            }
        }
        return count;
    }
};