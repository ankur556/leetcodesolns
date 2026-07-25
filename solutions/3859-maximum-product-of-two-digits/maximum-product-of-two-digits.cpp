class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> pq;
        while(n>0){
            pq.push(n%10);n/=10;
        }
        int sol=1;
        sol*=pq.top();pq.pop();sol*=pq.top();
        return sol;
    }
};