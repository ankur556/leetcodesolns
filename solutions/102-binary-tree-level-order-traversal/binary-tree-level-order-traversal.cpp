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
    vector<int> a;
    void helper(vector<vector<int>> & sol,int h,TreeNode * cur){
        if(cur==nullptr){return;}
        else{
                if(sol.size()==h){sol.push_back(a);}
                sol[h].push_back(cur->val);
                helper(sol,h+1,cur->left);
                helper(sol,h+1,cur->right);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        helper(sol,0,root);
        return sol;
    }
};