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
int cnt=0;
    int helper(TreeNode* root){
        if(root==nullptr){return 0;}
        int a=root->val;
        int b=helper(root->left);
        int c=helper(root->right);
        if(a>=b&&a>=c){cnt++;}
        return max({a,b,c});
    }
    int countDominantNodes(TreeNode* root) {
        helper(root);
        return cnt;
    }
};