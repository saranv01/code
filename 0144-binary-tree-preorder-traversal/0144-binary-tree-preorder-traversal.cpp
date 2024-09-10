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
    void recPreorder(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        res.push_back(root->val);
        recPreorder(root->left,res);
        recPreorder(root->right,res);

    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        recPreorder(root,res);
        return res;
    }
};