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
    void helper(TreeNode*a,vector<int>&sol){
        if(a==nullptr){return ;}
        else{sol.push_back(a->val);
        helper(a->left,sol);
        helper(a->right,sol);
        return ;}
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> sol;
        helper(root,sol);
        return sol;
    }
};
