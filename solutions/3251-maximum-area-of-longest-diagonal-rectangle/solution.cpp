class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    double maxDiag = 0;
    int maxArea = 0;
    for (const auto& rect : dimensions) {
        double diag = sqrt(pow(rect[0], 2) + pow(rect[1], 2));
        int area = rect[0] * rect[1];
        if (diag > maxDiag) {
            maxDiag = diag;
            maxArea = area;
        } else if (abs(diag - maxDiag) < 1e-9) {
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

};
