class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt++;
                element=nums[i];
            }
            else if(nums[i]==element){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return element;
    }
};