#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class SegTree {
public:
    SegTree(int _n) {
        n = _n;
        tree.resize(n * 4, 0);
    }

    int GetMax(int x) const {
        return GetRangeValueInternal(0, x, 1, 0, n - 1);
    }

    void UpdateValue(int index, int newValue) {
        UpdateValueInternal(index, newValue, 1, 0, n - 1);
    }

private:
    int n;
    vector<int> tree;

    int GetRangeValueInternal(int left, int right, int nodeIndex, int nodeRangeLeftIndex, int nodeRangeRightIndex) const {
        if (left > right) return 0;
        if (left == nodeRangeLeftIndex && right == nodeRangeRightIndex) return tree[nodeIndex];

        int rangeMid = (nodeRangeLeftIndex + nodeRangeRightIndex) / 2;
        int leftV = GetRangeValueInternal(left, min(right, rangeMid), nodeIndex * 2, nodeRangeLeftIndex, rangeMid);
        int rightV = GetRangeValueInternal(max(left, rangeMid + 1), right, nodeIndex * 2 + 1, rangeMid + 1, nodeRangeRightIndex);
        return max(leftV, rightV);
    }

    void UpdateValueInternal(int index, int newValue, int nodeIndex, int nodeRangeLeftIndex, int nodeRangeRightIndex) {
        if (nodeRangeLeftIndex == nodeRangeRightIndex) {
            tree[nodeIndex] = newValue;
            return;
        }

        int mid = (nodeRangeLeftIndex + nodeRangeRightIndex) / 2;
        int leftChild = nodeIndex * 2;
        int rightChild = leftChild + 1;
        if (index <= mid) {
            UpdateValueInternal(index, newValue, leftChild, nodeRangeLeftIndex, mid);
        } else {
            UpdateValueInternal(index, newValue, rightChild, mid + 1, nodeRangeRightIndex);
        }
        tree[nodeIndex] = max(tree[leftChild], tree[rightChild]);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        // Dynamically size the segment tree based on the maximum query coordinate
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        SegTree seg(max_x + 5); 
        set<int> obs;
        obs.insert(0);
        
        vector<bool> ans;
        for (const auto& q : queries) {
            int type = q[0];
            int x = q[1];
            
            if (type == 1) { 
                auto itr = obs.upper_bound(x);
                int l = *prev(itr);
                
                // Update the gap from the previous obstacle to x
                seg.UpdateValue(x, x - l);
                
                // ONLY dereference itr if there is an obstacle to the right
                if (itr != obs.end()) {
                    int r = *itr;
                    seg.UpdateValue(r, r - x);
                }
                obs.insert(x);
            } 
            else { 
                int sz = q[2];
                bool isValid = seg.GetMax(x) >= sz;
                
                if (!isValid) {
                    // Find the last obstacle before or at x safely
                    auto itr = obs.upper_bound(x);
                    int l = *prev(itr);
                    
                    if (x - l >= sz) {
                        isValid = true;
                    }
                }
                ans.push_back(isValid);
            }
        }
        return ans;
    }
};
