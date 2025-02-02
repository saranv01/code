class Solution {
public:
    bool check(vector<int>& nums) {
        int cntConversion=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+nums.size()+1)%nums.size()]) cntConversion++;
            if(cntConversion>1)return false;
        }
        return true;
    }
};