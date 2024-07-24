class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
          double avg=0;
          double total=0;
          for(int i=0;i<k;i++){
            total+=nums[i];
          } 
        avg=(double)total/k;
          if(nums.size()>k){
            for(int i=k;i<=nums.size();i++){
                total+=nums[i]-nums[i-k];
                cout<<total<<endl;
                avg=max(avg,(double)total/k);
            }
          }

         return avg;
    }
};