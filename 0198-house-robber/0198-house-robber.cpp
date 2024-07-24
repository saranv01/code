class Solution {
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int prevOne=nums[0];
        int prevTwo=max(nums[1],prevOne);

        int current=max(prevOne,prevTwo);

      
        for(int i=2;i<n;i++){
            current=max(prevOne+nums[i],prevTwo);
            prevOne=prevTwo;
            prevTwo=current;
        }

       return current;


    }
};