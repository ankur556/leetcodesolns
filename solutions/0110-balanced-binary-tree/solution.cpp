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
    int height(TreeNode* a){
        if(a==nullptr){
            return 0;
        }
        else{return 1+max(height(a->left),height(a->right));}
    }
    bool helper(TreeNode* root){
        if(root==nullptr){return true;}
        else if(abs(height(root->left)-height(root->right))<=1){return helper(root->right)&&helper(root->left);}
        else{return false;}
    }
    bool isBalanced(TreeNode* root) {
       return helper(root);   
    }
};
