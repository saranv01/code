/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
 
    pair<bool, int> isPerfectTree(TreeNode* root) {
        if (!root) return {true, 0};
        auto left = isPerfectTree(root->left);
        auto right = isPerfectTree(root->right);

        if (left.first && right.first && left.second == right.second) {
            return {true, left.second + 1}; 
        }
        
        return {false, 0}; 
    }

    int collectPerfectSubtreeSizes(TreeNode* root, vector<int>& sizes) {
        if (!root) return 0;
        
        auto result = isPerfectTree(root);
        
  
        if (result.first) {
            int size = (1 << result.second) - 1; // Size of a perfect tree of height 'h' is 2^h - 1
            sizes.push_back(size);
        }
        
        collectPerfectSubtreeSizes(root->left, sizes);
        collectPerfectSubtreeSizes(root->right, sizes);
        
        return 0;
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;
        
        collectPerfectSubtreeSizes(root, sizes);

        sort(sizes.begin(), sizes.end(), greater<int>());
        
        if (sizes.size() < k) return -1;
        
        return sizes[k - 1];
    }
};
