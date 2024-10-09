class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};  // If the array has less than 4 elements, return empty result.
        
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());  // Sort the array for the two-pointer approach.

        for(int i = 0; i < nums.size() - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates for `i`.

            for(int j = i + 1; j < nums.size() - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates for `j`.

                long long sum = (long long)nums[i] + nums[j];  // Use `long long` to avoid overflow.
                int l = j + 1;
                int r = nums.size() - 1;

                while(l < r) {
                    long long total = sum + nums[l] + nums[r];  // Compute total.

                    if(total == target) {
                        // Found a valid quadruplet.
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        // Skip duplicates for `l` and `r`.
                        while(l < r && nums[l] == nums[l - 1]) l++;
                        while(l < r && nums[r] == nums[r + 1]) r--;
                    } 
                    else if(total < target) {
                        l++;  // Move left pointer right to increase the sum.
                    } 
                    else {
                        r--;  // Move right pointer left to decrease the sum.
                    }
                }
            }
        }
        
        return ans;
    }
};
