/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to calculate subtree sums
    // Returns the sum of the tree rooted at 'root'
    int getSubtreeSums(TreeNode* root, vector<long long>& allSums) {
        if (root == nullptr) return 0;
        
        // Recursively get left and right sums
        int leftSum = getSubtreeSums(root->left, allSums);
        int rightSum = getSubtreeSums(root->right, allSums);
        
        // Current subtree sum = Node val + Left Sum + Right Sum
        long long currentSubtreeSum = root->val + leftSum + rightSum;
        
        // Store this sum in our vector
        allSums.push_back(currentSubtreeSum);
        
        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        vector<long long> allSums;
        
        // 1. Calculate all subtree sums
        long long totalSum = getSubtreeSums(root, allSums);
        
        long long maxProd = 0;
        
        // 2. Iterate through all sums to find the best split
        for (long long s : allSums) {
            // The two parts are 's' and 'totalSum - s'
            long long currentProd = s * (totalSum - s);
            if (currentProd > maxProd) {
                maxProd = currentProd;
            }
        }
        
        // Return result modulo 10^9 + 7 (standard for this LeetCode problem)
        return maxProd % 1000000007;
    }
};
