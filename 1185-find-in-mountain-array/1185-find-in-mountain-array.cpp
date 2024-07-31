/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //peak
        int l=0,h=mountainArr.length()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else h=mid-1;
        }
        int low=0,high=l;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)>target&&mountainArr.get(mid)>mountainArr.get(high)) low=mid+1;
            else if(mountainArr.get(mid)<target) low=mid+1;
            else high=mid-1; 
        }
        low=l,high=h=mountainArr.length()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) low=mid+1;
            else if(mountainArr.get(mid)>target&&mountainArr.get(mid)>mountainArr.get(high)) low=mid+1;
            else high=mid-1; 
        }
        return -1;
    }
};