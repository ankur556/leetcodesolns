class Solution {
public:
    // Helper: Traverses Root -> Right -> Left
    void helper(TreeNode* root, vector<int> &b, int level) {
        if (root == nullptr) {
            return;
        }


        if (b.size() == level) {
            b.push_back(root->val);
        }
        helper(root->right, b, level + 1);
        helper(root->left, b, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> b;
        helper(root, b, 0);
        return b;
    }
};
