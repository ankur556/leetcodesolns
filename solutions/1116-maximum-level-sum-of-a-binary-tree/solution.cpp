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
int getTreeHeight(TreeNode* root){
    if(root==nullptr){return 0;}
        else if(root->left==nullptr&&root->right==nullptr){return 1;}
    else if(root->left==nullptr){
        return 1+getTreeHeight(root->right);
    }
    else if(root->right==nullptr){return 1+getTreeHeight(root->left);}
    else{return 1+max(getTreeHeight(root->left),getTreeHeight(root->right));}
}
    void helper(vector<int> & arr,TreeNode* root,int curr){
        if(root==nullptr){return;}
        else if(root->left==nullptr && root->right==nullptr){arr[curr]+=root->val;return;}
        else if(root->left==nullptr){arr[curr]+=root->val;helper(arr,root->right,curr+1);}
        else if(root->right==nullptr){arr[curr]+=root->val;helper(arr,root->left,curr+1);}
        else{arr[curr]+=root->val;helper(arr,root->left,curr+1);helper(arr,root->right,curr+1);}
    }
    int maxLevelSum(TreeNode* root) {
        int lvl=0;
        int height=0;
        int h=0;
        if(root==nullptr){return 0;}
         h=getTreeHeight(root);
        vector<int> arr(h,0);
        int curr=0;
        helper(arr,root,curr);
        int sol=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>arr[sol]){sol=i;}
        }
        return sol+1;
    }
};
