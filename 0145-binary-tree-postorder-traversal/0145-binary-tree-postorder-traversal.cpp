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
private:
    void fn(TreeNode* r, vector<int>&arr){
        if(r==NULL)return;
        fn(r->left,arr);
        fn(r->right,arr);
        arr.push_back(r->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        fn(root,res);
        return res;
    }
};