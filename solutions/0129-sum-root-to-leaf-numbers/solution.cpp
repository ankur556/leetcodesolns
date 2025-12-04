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
int helper(TreeNode* a,int sum){
    if(a==nullptr){return sum;}
    else if(a->left==nullptr&&a->right==nullptr){sum=sum*10+a->val;return sum;}
    else if(a->left==nullptr){sum=sum*10+a->val;return helper(a->right,sum);}
    else if(a->right==nullptr){sum=sum*10+a->val;return helper(a->left,sum);}
    else{sum=sum*10+a->val;return helper(a->left,sum)+helper(a->right,sum);}
}
    int sumNumbers(TreeNode* root) {
        int sum=0;
        return helper(root,sum);
    }
};
