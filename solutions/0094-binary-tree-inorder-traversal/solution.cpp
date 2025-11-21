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
void helper(vector<int> & a,TreeNode* root){
    if(root==nullptr){return;}
    else if(root->left==nullptr){a.push_back(root->val);helper(a,root->right);}
    else if(root->right==nullptr){helper(a,root->left);a.push_back(root->val);}
    else{helper(a,root->left);a.push_back(root->val);helper(a,root->right);}
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>a;
        helper(a,root);
        return a;
    }
};
