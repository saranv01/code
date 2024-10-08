class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};  
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); 

        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue; 

            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;  

                long long sum = (long long)nums[i] + nums[j]; 
                int l = j + 1;
                int r = nums.size() - 1;

                while(l < r) {
                    long long total = sum + nums[l] + nums[r];

                    if(total == target) {
              
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                  
                        while(l < r && nums[l] == nums[l - 1]) l++;
                        while(l < r && nums[r] == nums[r + 1]) r--;
                    } 
                    else if(total < target) {
                        l++;  
                    } 
                    else {
                        r--;  
                    }
                }
            }
        }
        
        return ans;
    }
};
