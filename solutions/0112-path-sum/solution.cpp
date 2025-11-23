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
    bool helper(TreeNode* a,int sum,int t){
        sum=sum+a->val;
        if(sum==t&&a->left==nullptr&&a->right==nullptr){return true;}
        else if(sum!=t&&a->left==nullptr&&a->right==nullptr){return false;}
        else if(a->left==nullptr){return helper(a->right,sum,t);}
        else if(a->right==nullptr){return helper(a->left,sum,t);}
        else{return (helper(a->left,sum,t)||helper(a->right,sum,t));}
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        if(root==nullptr){return false;}
        return helper(root,sum,targetSum);
    }
};
