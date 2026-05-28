class Solution {
public:
    // Helper function returns true if the target is found, false otherwise
    bool findPath(TreeNode* root, int target, string& path) {
        if (root == nullptr) {
            return false;
        }
        if (root->val == target) {
            return true; // Stop searching!
        }
        
        // Try left
        path.push_back('L');
        if (findPath(root->left, target, path)) {
            return true;
        }
        path.pop_back(); // Backtrack if not found in the left subtree
        
        // Try right
        path.push_back('R');
        if (findPath(root->right, target, path)) {
            return true;
        }
        path.pop_back(); // Backtrack if not found in the right subtree
        
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath;
        string destPath;
        
        // 1. Get paths from root to both nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);
        
        // 2. Find the length of the common prefix (this leads to their LCA)
        int i = 0;
        while (i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]) {
            i++;
        }
        
        // 3. Build the final string
        string result = "";
        
        // For every remaining step in startPath, we must go 'U' (Up) to reach the LCA
        for (int j = i; j < startPath.size(); j++) {
            result += 'U';
        }
        
        // The remaining steps in destPath are the directions down from the LCA
        for (int j = i; j < destPath.size(); j++) {
            result += destPath[j];
        }
        
        return result;
    }
};
