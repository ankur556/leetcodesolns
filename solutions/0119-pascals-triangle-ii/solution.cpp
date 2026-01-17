class Solution {
public:
    vector<int> getRow(int rowIndex)  {
        vector<vector<int>> ans;
        
        for(int i = 0; i < rowIndex+1; i++) {
            // Create a row of size (i+1) filled with 1s
            // e.g., if i=2, creates [1, 1, 1]
            vector<int> row(i + 1, 1);
            
            // Calculate the middle elements (between the first and last 1)
            // We start j at 1 and end before the last element
            for(int j = 1; j < i; j++) {
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            
            ans.push_back(row);
        }
        
        return ans[rowIndex]; // Return is now OUTSIDE the loop
    }
};
