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
    TreeNode* serch(TreeNode* node,int val){
        if(node==nullptr){return nullptr;}
        if(node->val==val){return node;}
        else{
            if(node->val>val){return serch(node->left,val);}
            else{return serch(node->right,val);}
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return serch(root,val);
    }
};
