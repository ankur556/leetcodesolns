/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool iseq(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        } else if (node1 == nullptr) {
            return false;
        } else if (node2 == nullptr) {
            return false;
        } else if (node1->val != node2->val) {
            return false;
        } else {
            return (iseq(node1->left, node2->left) && iseq(node1->right, node2->right));
        }
    }
    bool isval(TreeNode* node1, TreeNode* node2) {
        if (node2 != nullptr && node1 == nullptr) {
            return false;
        }
        if (iseq(node1, node2)) {
            return true;
        } else {
            //cout<<node1->val<<" "<<node2->val<<endl; calls for all val but maybe the issue is wt the other fxn
            return (isval(node1->left, node2) || isval(node1->right, node2));
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isval(root, subRoot);
    }
};