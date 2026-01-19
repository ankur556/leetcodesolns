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
    void helper(vector<int> & a,TreeNode*root){
        if(root==nullptr){return;}
        else if(root->left==nullptr&&root->right==nullptr){
            a.push_back(root->val);
            return;
        }
        else if(root->left==nullptr){
            helper(a,root->right);a.push_back(root->val);
        }
        else if(root->right==nullptr){
            helper(a,root->left);a.push_back(root->val);
        }
        else{
            helper(a,root->left);a.push_back(root->val);helper(a,root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> a;
        unordered_map<int,int> map1;
        helper(a,root);
        for(int i: a){map1[i]++;}
        int max_cnt=0;
        for(int i=0;i<a.size();i++){
            if(map1[a[i]]>max_cnt){max_cnt=map1[a[i]];}
        }
        vector<int> sol;
        for(int i=0;i<a.size();i++){
            if(map1[a[i]]==max_cnt){map1[a[i]]=0;sol.push_back(a[i]);}
        }
        return sol;
    }
};
