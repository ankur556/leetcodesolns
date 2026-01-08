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
    void helper(vector<int> & help,TreeNode* root){
        if(root==nullptr){return;}
        //else if(root->left==nullptr&&root->right==nullptr){help.push_back(root->val);return;}
        else if(root->right==nullptr){helper(help,root->left);help.push_back(root->val);return;}
        else if(root->left==nullptr){help.push_back(root->val);helper(help,root->right);return;}
        else{
            helper(help,root->left);help.push_back(root->val);helper(help,root->right);return;
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> help;
        helper(help,root); 
        return help[k-1]; 
    }
};
