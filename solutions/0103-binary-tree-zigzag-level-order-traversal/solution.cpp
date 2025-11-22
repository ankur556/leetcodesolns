class Solution {
public:
    void helper(TreeNode* node, vector<vector<int>> &res, int level) {
        // Base case
        if (node == nullptr) {
            return;
        }

        // FIX 1: If this level doesn't exist in the vector yet, add a new row
        if (res.size() == level) {
            res.push_back({});
        }

        // Add current value to the specific level's row
        res[level].push_back(node->val);

        // FIX 2: Standard traversal (no need for else-if logic)
        helper(node->left, res, level + 1);
        helper(node->right, res, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        helper(root, result, 0);

        // FIX 3: Handle the Zigzag pattern
        // Traverse the result and reverse every ODD indexed row
        for (int i = 0; i < result.size(); i++) {
            if (i % 2 != 0) {
                // Level 1, 3, 5... need to be reversed (Right -> Left)
                reverse(result[i].begin(), result[i].end());
            }
        }

        return result;
    }
};
