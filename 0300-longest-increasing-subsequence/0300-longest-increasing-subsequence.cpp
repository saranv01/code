class Solution {
private:
    int findLowerBound(vector<int>&tempArray,int element){
        int low=0;
        int high=tempArray.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(tempArray[mid]>=element) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1)return 1;
        vector<int>temp;
        int cnt=1;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                cnt++;
            }
            else{
                int lb=findLowerBound(temp,nums[i]);
                temp[lb]=nums[i];
            
            }
        }
        return cnt;
    }
};