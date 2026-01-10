class Solution {
public:
    void helper(TreeNode* a, vector<string> & sol, string b){
        if(a == nullptr){ return; }
        
        if(b.size() == 0){
            b = b + to_string(a->val);
        } else {
            b = b + "->" + to_string(a->val);
        }

        if(a->left == nullptr && a->right == nullptr){
            sol.push_back(b);
            return;
        }

        if(a->left != nullptr){
            helper(a->left, sol, b);
        }
        if(a->right != nullptr){
            helper(a->right, sol, b);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sol;
        string a;
        helper(root, sol, a);
        return sol;
    }
};
