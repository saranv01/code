class Solution {
public:
    int setFit(vector<int>&nums,int threshold,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=*max_element(nums.begin(),nums.end());
        int high=1;
        int ans;
        while(high<=low){
            int mid=low+(high-low)/2;
            int sum=setFit(nums,threshold,mid);
            if(sum<=threshold){
                low=mid-1;
                ans=mid;
            }
            else{
                high=mid+1;
            }
        }
        return ans;
    }
};