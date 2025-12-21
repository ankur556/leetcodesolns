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
        else if(a->right==nullptr&&a->left==nullptr){sol.push_back(a->val);return;}
        else if(a->left==nullptr){sol.push_back(a->val);helper(sol,a->right);return;}
        else if(a->right==nullptr){sol.push_back(a->val);helper(sol,a->left);return;}
        else{sol.push_back(a->val);helper(sol,a->left);helper(sol,a->right);}
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> sol;
        helper(sol,root);
        return sol;
    }
};
