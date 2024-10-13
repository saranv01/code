class Solution {
public:

    int generateFromSubarray(unordered_map<int, int>& freq, int x) {
        vector<pair<int, int>> vec;
        
        for (auto& entry : freq) {
            vec.push_back({entry.second, entry.first}); 
        }
        
      
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second > b.second; 
            return a.first > b.first;
        });
        

        int sum = 0, added = 0;
        for (int i = 0; i < vec.size() && added < x; ++i) {
            sum += vec[i].second * vec[i].first; 
            added++;
        }
        
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        

        unordered_map<int, int> freq;
        for (int i = 0; i < k; ++i) {
            freq[nums[i]]++;
        }

        ans.push_back(generateFromSubarray(freq, x));
        

        for (int i = k; i < n; ++i) {
    
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);
            
        
            freq[nums[i]]++;
            

            ans.push_back(generateFromSubarray(freq, x));
        }
        
        return ans;
    }
};