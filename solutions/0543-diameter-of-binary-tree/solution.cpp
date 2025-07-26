class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    // Helper function returns the height of a node but also
    // updates the max diameter found so far.
    int height(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively find the height of the left and right subtrees.
        int leftHeight = height(node->left, diameter);
        int rightHeight = height(node->right, diameter);

        // The longest path through this node is the sum of the two heights.
        // Update the overall maximum diameter if this path is longer.
        diameter = std::max(diameter, leftHeight + rightHeight);

        // Return the height of the tree rooted at this node.
        return 1 + std::max(leftHeight, rightHeight);
    }
};
