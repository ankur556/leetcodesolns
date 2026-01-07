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
    void filler(vector<int> & sol,TreeNode* root){
        if(root==nullptr){return;}
        else if(root->left==nullptr&&root->right==nullptr){
            sol.push_back(root->val);
        }
        else if(root->left==nullptr){sol.push_back(root->val);filler(sol,root->right);}
        else if(root->right==nullptr){filler(sol,root->left);sol.push_back(root->val);}
        else{
            filler(sol,root->left);
            sol.push_back(root->val);
            filler(sol,root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> sol;
        filler(sol,root);
        int left=0;int right=sol.size()-1;
        while (left < right) {
            int currentSum = sol[left] + sol[right];
            if (currentSum == k) {
                return true;
            }
            if (currentSum < k) {
                left++; // Need a larger sum
            } else {
                right--; // Need a smaller sum
            }
        }
        return false;
    }
};
