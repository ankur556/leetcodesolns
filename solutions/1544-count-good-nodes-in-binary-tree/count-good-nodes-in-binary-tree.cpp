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
int good_nodes=0;
    void helper(TreeNode* root,int val){
        if(root==nullptr){return ;}
        else{
            if(root->val>=val){good_nodes++;}
            val=max(root->val,val);
            helper(root->left,val);
            helper(root->right,val);
        }
    }
    int goodNodes(TreeNode* root) {
        helper(root,-1e8);
        return good_nodes;
    }
};