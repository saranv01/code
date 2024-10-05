class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int flag=-1;
        
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                flag=i;
                break;
            }
        }
        if(flag==-1) {
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=nums.size()-1;i>flag;i--){
            if(nums[i]>nums[flag]){
                swap(nums[i],nums[flag]);
                break;
            }
        }
        reverse(nums.begin()+flag+1,nums.end());
  
    }
};