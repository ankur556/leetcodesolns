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
    void helper(vector<int> & sol,TreeNode* a){
        if(a==nullptr){return;}
        else{
            helper(sol,a->left);
            sol.push_back(a->val);
            helper(sol,a->right);
            return;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        helper(sol,root);
        return sol;
    }
};
