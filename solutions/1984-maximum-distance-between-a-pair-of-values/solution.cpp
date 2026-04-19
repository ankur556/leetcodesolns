class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i, j;
        for (i = 0, j = 0; i < A.size() && j < B.size(); j++){
            if(A[i]>B[j]){i++;}}
        return max(0, j - i - 1);
    }
};
