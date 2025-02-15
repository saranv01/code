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
    bool checkSymmetric(TreeNode*r1, TreeNode*r2){
        if(r1==nullptr||r2==nullptr)return r1==r2;
        if(r1->val==r2->val){
            return(checkSymmetric(r1->left,r2->right)&&checkSymmetric(r1->right,r2->left));
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        if(root->left==nullptr&&root->right==nullptr)return true;
        if(root->left&&root->right)
        return checkSymmetric(root->left,root->right);        
        return false;
    }
};