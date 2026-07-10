class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        // --- 1. First Binary Search: Find the correct row ---
        int l = 0;
        int r = matrix.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (matrix[mid][0] == target) {
                return true; 
            } else if (matrix[mid][0] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        // If r < 0, the target is smaller than the very first element in the matrix
        if (r < 0) {
            return false;
        }
        
        // The correct row where our target might exist is now at pointer 'r'
        int targetRow = r; 
        
        // --- 2. Second Binary Search: Search within that specific row ---
        l = 0;
        r = matrix[targetRow].size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return false;
    }
};