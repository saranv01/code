class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        for(int i=0;i<ans.size();i++){
            int n=nums[i];
            for(int j=0;j<n;++j){
                if((j|(j+1))==n){
                    ans[i]=j;
                    break;
                }
            }
        }   
        return ans;
    }
};