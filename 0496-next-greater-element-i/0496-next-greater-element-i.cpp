class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int,int> mp;
        vector<int>res;
        for(int i=nums2.size()-1;i>=0;i--){
            if(stk.empty()){
                mp[nums2[i]]=-1;
            }
            else if(stk.top()>nums2[i]){
                mp[nums2[i]]=stk.top();
            }     
            else{
            while(!stk.empty()&&stk.top()<nums2[i]){
            stk.pop();
            }
            if(stk.empty()) mp[nums2[i]]=-1;
            else mp[nums2[i]]=stk.top();
            }
            stk.push(nums2[i]);
        }


        for(int i=0;i<nums1.size();i++){
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};