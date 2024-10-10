class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> smallest(n), largest(n);

        // Fill smallest array
        smallest[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            smallest[i] = min(smallest[i - 1], nums[i]);
        }

        // Fill largest array
        largest[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            largest[i] = max(largest[i + 1], nums[i]);
        }

        // Two pointers to find the maximum ramp
        int i = 0, j = 0, maxWidth = 0;
        while (j < n && i < n) {
            if (smallest[i] <= largest[j]) {
                maxWidth = max(maxWidth, j - i);
                j++; // Try to increase the width
            } else {
                i++; // Move i forward to find a smaller smallest[i]
            }
        }

        return maxWidth;
    }
};
