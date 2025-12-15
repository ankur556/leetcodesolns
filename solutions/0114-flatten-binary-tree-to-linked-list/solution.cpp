class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return; // Handle empty tree edge case
        
        vector<int> b;
        helper(root, b); // Your helper gathers values: [1, 2, 3, 4, 5, 6]
        
        TreeNode* curr = root; 
        
        // Start from i=1 because root (b[0]) is already set
        for(int i = 1; i < b.size(); i++){
            // 1. Clear the left side (rule of flattened tree)
            curr->left = nullptr;
            
            // 2. Create/Link the next node to the RIGHT
            curr->right = new TreeNode(b[i]);
            
            // 3. Move the 'curr' pointer forward
            curr = curr->right;
        }
    }
    
    // Your helper function (slightly cleaned up)
    void helper(TreeNode* a, vector<int> &b){
        if(a == nullptr) return;
        b.push_back(a->val);
        helper(a->left, b);
        helper(a->right, b);
    }
};
