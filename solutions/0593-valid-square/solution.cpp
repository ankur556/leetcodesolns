class Solution {
public:
    // Helper function to calculate squared distance
    long long dist(vector<int>& p1, vector<int>& p2) {
        return 1LL * (p1[0] - p2[0]) * (p1[0] - p2[0]) + 
               1LL * (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // 1. Calculate distances between all 6 pairs
        vector<long long> d = {
            dist(p1, p2), dist(p1, p3), dist(p1, p4),
            dist(p2, p3), dist(p2, p4), dist(p3, p4)
        };

        // 2. Sort the distances to easily find sides and diagonals
        sort(d.begin(), d.end());

        // 3. Validation Logic:
        // - The smallest distance (side) must be > 0.
        // - The first 4 distances (sides) must be equal.
        // - The last 2 distances (diagonals) must be equal.
        // - (Implicitly checked by sorting): Diagonals must be larger than sides.
        
        return d[0] > 0 && 
               d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && 
               d[4] == d[5];
    }
};
