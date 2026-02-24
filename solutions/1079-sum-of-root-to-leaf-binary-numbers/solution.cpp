class Solution {
public:
    // 'currentSum' tracks the value of the binary path from root to here
    void helper(int currentSum, int &sol, TreeNode* h) {
        if (h == nullptr) return;

        // Shift left and add current bit: (currentSum * 2) + h->val
        currentSum = (currentSum << 1) | h->val;

        // If we reached a leaf, add the finished path value to our total
        if (h->left == nullptr && h->right == nullptr) {
            sol += currentSum;
            return;
        }

        // Continue down the tree
        helper(currentSum, sol, h->left);
        helper(currentSum, sol, h->right);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sol = 0;
        helper(0, sol, root);
        return sol;
    }
};
