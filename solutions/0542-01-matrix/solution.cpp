class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q; 
        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    for(auto dir: dirs){
                        int ni = i + dir.first;
                        int nj = j + dir.second;
                        if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                            if(mat[ni][nj] == 0){
                                q.push({i,j});
                                visited[i][j] = true; 
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        while(!q.empty()){
            pair<int,int> a = q.front();
            q.pop();
            for(auto dir: dirs){
                int r = a.first;
                int c = a.second;
                int rc = r + dir.first;
                int cc = c + dir.second;
                
                if(rc >= 0 && rc < m && cc >= 0 && cc < n){
                    if(mat[rc][cc] == 1 && !visited[rc][cc]){
                        mat[rc][cc] = mat[r][c] + 1;
                        visited[rc][cc] = true; 
                        q.push({rc, cc}); 
                    }
                }
            }
        }
        return mat;
    }
};
