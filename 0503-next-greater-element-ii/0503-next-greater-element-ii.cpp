class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>stk;
        int n=nums.size();
        vector<int>res(n);
        for(int i=2*nums.size()-1;i>=0;i--){
            while(!stk.empty()&&nums[i%n]>=stk.top()){
                stk.pop();
            }
           if(stk.empty()){
             if(i<n) res[i]=-1;
            }
            else{
                if(i<n){
                    res[i]=stk.top();
                }
            }
            stk.push(nums[i%n]);
        }
        return res;   
    }
};