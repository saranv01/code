class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>memo(nums.size(),false);
        memo[nums.size()-1]=true;
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j<=nums[i];j++){
                if((i+j)<nums.size()){
                    if(memo[i+j]){
                        memo[i]=true;
                        break;
                    }
                }
            }
        }
        return memo[0];
    }
};