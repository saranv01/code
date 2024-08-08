class Solution {
public:
    bool validateCapacity(vector<int>& weights, int days,int capacity){
        int day=1;
        int temp_weight=0;
        for(int i=0;i<weights.size();i++){

            if(temp_weight+weights[i]>capacity){
                day++;
                temp_weight=weights[i];
                continue;
            }
            else
            temp_weight+=weights[i];
        }
        if(day<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int x:weights) high+=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(validateCapacity(weights,days,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};