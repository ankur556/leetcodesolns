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
 bool issymm(TreeNode* left,TreeNode* right){
if(left==nullptr&&right==nullptr){return true;}
else if(left==nullptr){return false;}
else if(right==nullptr){return false;}
else if(left->val==right->val){return(issymm(left->left,right->right)&&issymm(left->right,right->left));}
else{return false;}
 }
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        return issymm(left,right);
    }
};
