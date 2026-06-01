class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: key not found
        if (!root) return nullptr;

        // Step 1: Search for the node
        if (key < root->val) {
            // Reconnect the left child after deletion in the left subtree
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            // Reconnect the right child after deletion in the right subtree
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Step 2: Node found! Handle the 3 cases.

            // Case 1 & 2: Node has 0 or 1 child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root; // Prevent memory leak
                return temp;
            }
            if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has 2 children
            // Find the inorder successor (smallest node in the right subtree)
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }

            // Copy the successor's value into the current node
            root->val = successor->val;

            // Recursively delete the successor from the right subtree
            root->right = deleteNode(root->right, successor->val);
        }
        
        return root;
    }
};
