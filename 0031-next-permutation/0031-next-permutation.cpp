class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        int breakPoint=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPoint=i;
                break;
            }
        }
        if(breakPoint==-1) {
            sort(nums.begin(),nums.end());
            return;
        }
        
        int swpIndex=-1;
        int nextMax=INT_MAX;
        for(int i=n-1;i>breakPoint;i--){
            if(nums[i]>nums[breakPoint]&&nums[i]<nextMax){
                swpIndex=i;
                nextMax=nums[i];
            }
        }
        swap(nums[breakPoint],nums[swpIndex]);
        sort(nums.begin()+breakPoint+1, nums.end());
        return;
    }
};