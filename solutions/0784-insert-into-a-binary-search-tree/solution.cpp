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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         TreeNode* next=root;
        if (root==nullptr){next=new TreeNode();next->val=val;root=next;return root;}
        
        TreeNode* a =root;
        while(next!=nullptr){a=next;if(val>a->val){next=next->right;}else{next=next->left;}}
        
        next=new TreeNode();
        next->val=val;
        if(val>a->val){a->right=next;}
        else{a->left=next;}
        return root;
    }
};
