
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Convert wordDict to an unordered_set for faster lookups
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // dp[i] will be true if s[0..i) can be segmented into words from wordSet
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;  // Empty string is always a valid segmentation
        
        // Check every substring s[0..i)
        for (int i = 1; i <= s.size(); ++i) {
            // Check every possible split point j
            for (int j = 0; j < i; ++j) {
                // If s[0..j) can be segmented and s[j..i) is in wordSet
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};