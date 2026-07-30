class DSU {
public:
    vector<int> par;
    vector<int> weight;
    DSU(int n) {
        par.resize(n);
        weight.resize(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int findpar(int i) {
        if (par[i] == i) {
            return i;
        } else {
            return par[i] = findpar(par[i]);
        }
    }
    bool aretog(int i, int j) {
        int par_i = findpar(i);
        int par_j = findpar(j);
        return par_i == par_j;
    }
    void unite(int i, int j) {
        int par_i = findpar(i);
        int par_j = findpar(j);
        if (weight[par_j] > weight[par_i]) {
            weight[par_j] += weight[par_i];
            par[par_i] = par_j;
        } else {
            weight[par_i] += weight[par_j];
            par[par_j] = par_i;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++) {
            int f = edges[i][0];
            int s = edges[i][1];
            if (dsu.aretog(f, s)) {
                return {f, s};
            } else {
                dsu.unite(f, s);
            }
        }
        return {0, (int)edges.size() - 1};
    }
};