class Solution {
public:
    void Merge(vector<int>&arr,int low,int high,int mid){
            vector<int>temp;
            int left=low;
            int right=mid+1;
            while(left<=mid&&right<=high){
                if(arr[left]<arr[right]){
                    temp.push_back(arr[left]);
                    left++;
                }
                else{
                    temp.push_back(arr[right]);
                    right++;
                }
            }
            while(left<=mid){
                    temp.push_back(arr[left]);
                    left++;                
            }
            while(right<=high){
                    temp.push_back(arr[right]);
                    right++;                
            }
            for(int i=0;i<temp.size();i++){
                arr[low+i]=temp[i];
            }
    }

    void MergeSort(vector<int>& nums,int low,int high){
        if(low>=high) return;
        int mid=low+(high-low)/2;

                MergeSort(nums,low,mid);
                MergeSort(nums,mid+1,high);
                Merge(nums,low,high,mid);

        


    }

    vector<int> sortArray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        MergeSort(nums,low,high);

        return nums;
    }
};