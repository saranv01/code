class Solution {
public:
    void findCombination(vector<int>&candidates, int ind,int target,vector<int>&ds,vector<vector<int>>&ans,int n){

        if(ind==n||target<=0){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findCombination(candidates,ind,target-candidates[ind],ds,ans,n);
            ds.pop_back();
        }

        findCombination(candidates,ind+1,target,ds,ans,n);


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(candidates,0,target,ds,ans,n);
        return ans;
    }
};