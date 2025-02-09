/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* findLowest(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr||root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = findLowest(root->left, p, q);
        TreeNode* right = findLowest(root->right, p, q);
        if (left == nullptr) {
            return right;
        }
        else if(right==nullptr){
            return left;
        } 
        else {
            return root;
        }
        return nullptr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLowest(root, p, q);
    }
};