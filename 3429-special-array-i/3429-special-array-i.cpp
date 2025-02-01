class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()<2) return true;
        for(int i=0,j=1;j<nums.size();i+=1,j+=1){
            if((nums[i]+nums[j])%2!=1)return false;
        }
        return true;
    }
};