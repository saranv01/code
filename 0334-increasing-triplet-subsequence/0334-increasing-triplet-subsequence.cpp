class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {

        if(nums.size()<3) return false;
        int f1=INT_MAX;
        int f2=INT_MAX;
        for(int i=0;i<nums.size();i++){
           if(nums[i]<f1){
            f1=nums[i];
           }
           else if(f1<nums[i]&&nums[i]<f2){
            f2=nums[i];
           }
           else if(f2<nums[i]) return true;
           
        }
        return false;

        
    }
};