class Solution {
public:
    bool validDates(vector<int>&bloomDay,int m,int k,int day){
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++ ){
            if(bloomDay[i]<=day){
                cnt++;
            }
            if(cnt==k || bloomDay[i]>day){
           
            if(cnt==k)
                m--;
            cnt=0;
            }
        }
        if(cnt>=k) m--;
        if(m<=0) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size()<((long long)m*k)) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(validDates(bloomDay,m,k,mid)) high=mid-1;
            else low =mid+1;
        }
        return low;
    }
};