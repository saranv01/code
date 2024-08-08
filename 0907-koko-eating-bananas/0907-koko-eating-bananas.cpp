class Solution {
public:
    bool valideating(vector<int>&piles, int h, int m){
        long long cnt =0;
        for(int i=0;i<piles.size();i++){
            cnt+= ceil(piles[i] + m - 1) / m;
        }
        if(cnt<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low =1;
        while(low<=high){
            int mid=low+((high-low)/2);
            if(valideating(piles,h,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};