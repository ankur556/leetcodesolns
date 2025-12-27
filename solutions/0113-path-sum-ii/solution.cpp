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
    void helper(vector<vector<int>> & sol,TreeNode* a,int sum,int target,vector<int> curr){
        if(a==nullptr){return;}
        else if(a->val+sum==target){if(a->left==nullptr&&a->right==nullptr){curr.push_back(a->val);sol.push_back(curr);return;}else{        curr.push_back(a->val);sum+=a->val;
        if(a->left==nullptr&&a->right==nullptr){return;}
        else if(a->left==nullptr){
            helper(sol,a->right,sum,target,curr);return;
        }
        else if(a->right==nullptr){
            helper(sol,a->left,sum,target,curr);return;
        }
        else{helper(sol,a->left,sum,target,curr);helper(sol,a->right,sum,target,curr);return;}}}
        
        else{
        curr.push_back(a->val);sum+=a->val;
        if(a->left==nullptr&&a->right==nullptr){return;}
        else if(a->left==nullptr){
            helper(sol,a->right,sum,target,curr);return;
        }
        else if(a->right==nullptr){
            helper(sol,a->left,sum,target,curr);return;
        }
        else{helper(sol,a->left,sum,target,curr);helper(sol,a->right,sum,target,curr);return;}
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> sol;
        vector<int> curr;
        int sum=0;
        TreeNode* a=root;
        helper(sol,a,sum,targetSum,curr);
        return sol;
    }
};
