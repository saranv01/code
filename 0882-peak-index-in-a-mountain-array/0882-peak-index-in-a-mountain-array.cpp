class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]>arr[mid+1]){
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
        
    }
};