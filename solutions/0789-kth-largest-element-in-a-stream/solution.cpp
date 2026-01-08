class KthLargest {
public:
    // A min-heap to store only the 'k' largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kSize;

    KthLargest(int k, vector<int>& nums) {
        kSize = k;
        for (int x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        // If the heap exceeds size k, pop the smallest element
        if (minHeap.size() > kSize) {
            minHeap.pop();
        }
        
        // The root of the min-heap is the kth largest element
        return minHeap.top();
    }
};
