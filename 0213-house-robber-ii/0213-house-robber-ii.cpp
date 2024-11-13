class Solution {
public:
    int helpRob(vector<int>&arr,int n,vector<int>&mem){
        if(n==0) return arr[0];
        if(n<0)return 0;
        if(mem[n]!=-1)return mem[n];
        return mem[n]= max(arr[n]+helpRob(arr,n-2,mem),0+helpRob(arr,n-1,mem));
    }
    int robbed(vector<int>& nums){
        vector<int>a1,a2;
        vector<int>mem1(nums.size()-1,-1);
        vector<int>mem2(nums.size()-1,-1);
        for(int i=0;i<nums.size();i++){
            if(i!=0)a1.push_back(nums[i]);
            if(i!=nums.size()-1)a2.push_back(nums[i]);
        }
        return max(helpRob(a1,nums.size()-2,mem1),helpRob(a2,nums.size()-2,mem2));
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        return robbed(nums);
    }
};