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
    void helper(vector<int>& c,TreeNode* node){
        if(node==nullptr){return;}
        else if(node->left==nullptr){c.push_back(node->val);helper(c,node->right);return;}
         else if(node->right==nullptr){c.push_back(node->val);helper(c,node->left);return;}
        else{c.push_back(node->val);helper(c,node->left);helper(c,node->right);return;}
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        helper(a,root1);
        helper(b,root2);
        for(int i:b){a.push_back(i);}
        sort(a.begin(),a.end());
        return a;
    }
};
