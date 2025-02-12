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
    int lvl=1;
    void rightView(TreeNode* root, vector<int>&ans,int cur){
        if(root == nullptr) return;
        cur++;
        if(lvl==cur){
          ans.push_back(root->val);
          lvl++;   
        }
        rightView(root->right,ans,cur);
        rightView(root->left,ans,cur);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        rightView(root,ans,0);
        return ans;
    }
};