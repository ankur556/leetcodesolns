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
    bool isSameTree(TreeNode* a, TreeNode* b) {
    if(a==nullptr&&b==nullptr){return true;}
    else if(a==nullptr){return false;}
    else if (b==nullptr){return false;}
    else if(a->val==b->val){return isSameTree(a->left,b->left)&&isSameTree(a->right,b->right);}
    else{return false;}
    }
};
