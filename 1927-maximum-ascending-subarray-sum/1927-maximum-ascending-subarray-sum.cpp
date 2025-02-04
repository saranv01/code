class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int tempSum=nums[0];
        int maxSum=tempSum;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                tempSum+=nums[i];
            }
            else{
                tempSum=nums[i];
            }
            if(maxSum<tempSum) maxSum=tempSum;
        }
        return maxSum;
    }
};