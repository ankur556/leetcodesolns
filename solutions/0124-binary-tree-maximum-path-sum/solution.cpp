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
    int minr=-1e7;
    int maxsum(TreeNode* node){
        if(node==nullptr){return 0;}
        else{
            if(node->val>minr){minr=node->val;}
            int lmax=maxsum(node->left);
            int rmax=maxsum(node->right);
            minr=max(node->val+max(lmax,0)+max(rmax,0),minr);
            return node->val+max(max(lmax,rmax),0);
        }
    }
    int maxPathSum(TreeNode* root) {
        
        int k= maxsum(root); 
        return  minr;
    }
};
