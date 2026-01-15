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
    void helper(TreeNode* root,int lvl,vector<vector<int>>& temp){
        if(root==nullptr){return;}
        else if(root->left==nullptr&&root->right==nullptr){
            if(lvl>=temp.size()){vector<int>a;temp.push_back(a);}
            temp[lvl].push_back(root->val);return;
        }
        else if(root->left==nullptr){
            if(lvl>=temp.size()){vector<int>a;temp.push_back(a);}
            temp[lvl].push_back(root->val);
            helper(root->right,lvl+1,temp);
            return;
        }
        else if(root->right==nullptr){
            if(lvl>=temp.size()){vector<int>a;temp.push_back(a);}
            helper(root->left,lvl+1,temp);
            temp[lvl].push_back(root->val);
            return;
        }
        else {
            if(lvl>=temp.size()){vector<int>a;temp.push_back(a);}
            helper(root->left,lvl+1,temp);
            temp[lvl].push_back(root->val);
            helper(root->right,lvl+1,temp);
            return;
        }
    }
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> temp;
        int lvl=0;
        helper(root,lvl,temp);
        for(int i=0;i<temp.size()/2;i++){swap(temp[i],temp[temp.size()-1-i]);}
        return temp;
    }
};
