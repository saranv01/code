class Solution {
public:

    void merge(vector<int>&nums,int low,int mid,int high){
        int ans=0;
        int left=low;
        int right=mid+1;
        vector<int>temp;
        while(left<=mid&&right<=high){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    
        
    }
    int countPairs(vector<int>&nums,int low,int mid, int high){
        int cnt=0;
        int right=mid+1;
        for(int i=low;i<=mid;i++){
            while(right<=high&&(long)nums[i]>(long)2*nums[right])right++;
            cnt+=(right-(mid+1));            
        }
        return cnt;
    }
    
    int mergeSort(vector<int>&nums, int low, int high){
       int ans=0;
        while(low<high){
            int mid=low+(high-low)/2;
            ans+=mergeSort(nums,low,mid);
            ans+=mergeSort(nums,mid+1,high);
            ans+=countPairs(nums,low,mid,high);
            merge(nums,low,mid,high);
            return ans;
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        return mergeSort(nums,low,high);
    }
};