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
    int sum=0;
    void helper(int val,TreeNode* root){
        if(root==nullptr){return;}
        val*=10;
        val+=root->val;
        if(root->left==nullptr&&root->right==nullptr){sum+=val;return;}
        else{helper(val,root->left);helper(val,root->right);}
    }
    int sumNumbers(TreeNode* root) {
        helper(0,root);
        return sum;
    }
};