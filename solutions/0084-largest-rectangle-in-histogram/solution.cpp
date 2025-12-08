class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            // Use 0 as the height for the "virtual" bar at index n 
            // to force popping remaining elements in the stack
            int currentHeight = (i == n) ? 0 : heights[i];

            // Maintain monotonic increasing stack
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                
                // If stack is empty, width extends from 0 to i
                // If not, width extends from (st.top() + 1) to (i - 1)
                int width = st.empty() ? i : (i - st.top() - 1);
                
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
