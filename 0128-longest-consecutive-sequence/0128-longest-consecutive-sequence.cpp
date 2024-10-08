class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int p1=0;
        int p2=1;
        int sum=1;
        sort(nums.begin(),nums.end());
        while(p2<nums.size()){
            if((nums[p2-1]+1)==nums[p2]){
                sum=max(p2-p1+1,sum);
                p2++;
            }
            else if((nums[p2-1])==nums[p2]){
                p2++;
                p1++;
            }
            else{
                p1=p2;
                p2++;
            }
        }
        
        return sum;
    }
};
