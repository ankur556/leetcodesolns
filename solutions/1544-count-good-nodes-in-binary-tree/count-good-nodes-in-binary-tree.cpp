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
    // helper fxn helps count the val;
    int sol=0;
    void helper(TreeNode * a,long long cur){
        if(a==nullptr)return;
        if(a->val>=cur){cur=a->val;sol++;}
        helper(a->right,cur);
        helper(a->left,cur);
    }
    int goodNodes(TreeNode* root) {
        helper(root,-1e15);
        return sol;
    }
};