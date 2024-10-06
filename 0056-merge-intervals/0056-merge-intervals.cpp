class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        while (i < intervals.size()) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);

            } else
                ans.back()[1] = max(intervals[i][1],ans.back()[1]);
            i++;
        }
        return ans;
    }
};