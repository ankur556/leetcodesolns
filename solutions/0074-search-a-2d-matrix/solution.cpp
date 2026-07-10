class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) {
            return false;
        }
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
        if (r < 0) {
            return false;
        }
        int targetRow = r;
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
