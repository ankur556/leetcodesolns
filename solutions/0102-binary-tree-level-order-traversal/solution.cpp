class Solution {
public:
    // 1. Added '&' to pass by reference
    // 2. Renamed variables for clarity (optional but recommended)
    void dfs(TreeNode* node, int level, vector<vector<int>>& result) {
        if (node == nullptr) {
            return;
        }


        if (result.size() == level) {
            result.push_back({});
        }
 

        result[level].push_back(node->val);
       level++;
        dfs(node->left, level, result);
        dfs(node->right, level, result);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int i=0;
        dfs(root, i, ans);
        return ans;
    }
};
