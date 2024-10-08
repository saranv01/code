class Solution {
public:
    bool binarySearch(vector<vector<int>>&matrix, int target){
        int low=0;
        int high=(matrix.size()*matrix[0].size())-1;
        int m=matrix[0].size();
        while(low<=high){
            int mid=low+(high-low);
            if(matrix[mid/m][mid%m]==target)return true;
            else if(matrix[mid/m][mid%m]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     return binarySearch(matrix,target);   
    }
};