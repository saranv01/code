class Solution {
public:
    void findCombination(vector<int>&candidates,int ind,int target,vector<int>&ds,vector<vector<int>>&ans){
            
                if(target==0){
                    // cout<<ind<<endl;
                    ans.push_back(ds);
                    return;
                }
     
          
            for(int i=ind;i<candidates.size();i++){
                if(i!=ind&&candidates[i]==candidates[i-1]) continue;
                    if(target>=candidates[i]){
                        ds.push_back(candidates[i]);
                        findCombination(candidates,i+1,target-candidates[i],ds,ans);
                        ds.pop_back();
                    }
            
            }


    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        findCombination(candidates,0,target,ds,ans);
        return ans;
    }
};