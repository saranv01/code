class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int maxi=0;
        for(int i=0;i<nums.size()-1;i++){
            int cnt=0;
            while(i<nums.size()-1&&nums[i]<nums[i+1]){
                    cnt++;
                    if(cnt>maxi)maxi=cnt;
                    i++;
            }
            cnt=0;
            while(i<nums.size()-1&&nums[i]>nums[i+1]){
                cnt++;
                if(cnt>maxi)maxi=cnt;
                i++;
            }
            if(i<nums.size()-1&&nums[i]<nums[i+1])i--;
        }
        return maxi+1;
    }
};