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
 void helper(TreeNode* root){
    if(root==nullptr){return;}
    else if(root->left==nullptr||root->right==nullptr){if(root->left!=nullptr){swap(root->left,root->right);helper(root->right);}else if(root->right!=nullptr){swap(root->left,root->right);helper(root->left);}else{return;}}
    else{
    swap(root->left,root->right);
    helper(root->left);
    helper(root->right);}
 }
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
