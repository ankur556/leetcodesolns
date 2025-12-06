class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int sum = 0;

        // Check if the left child exists
        if (root->left != nullptr) {
            // Check if the left child is a LEAF
            if (root->left->left == nullptr && root->left->right == nullptr) {
                sum += root->left->val; // It's a left leaf, add it
            } else {
                // It's not a leaf, so traverse deeper into the left side
                sum += sumOfLeftLeaves(root->left);
            }
        }

        // Always traverse the right side to find left leaves there
        sum += sumOfLeftLeaves(root->right);

        return sum;
    }
};
