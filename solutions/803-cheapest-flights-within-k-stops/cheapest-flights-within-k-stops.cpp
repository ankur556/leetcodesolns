class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Distance array initialized to infinity
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Up to k stops means at most k + 1 flight edges
        for (int i = 0; i <= k; ++i) {
            vector<int> temp = dist; // Copy current state

            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if (dist[u] != INT_MAX && dist[u] + price < temp[v]) {
                    temp[v] = dist[u] + price;
                }
            }

            dist = temp; // Apply updates for this step
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};