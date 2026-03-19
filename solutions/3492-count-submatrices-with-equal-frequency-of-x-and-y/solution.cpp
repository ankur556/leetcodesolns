class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<pair<int,bool>>> a;
        for(int i=0;i<grid.size();i++){vector<pair<int,bool>> b;for(int j=0;j<grid[0].size();j++){b.push_back({0,false});}a.push_back(b);}
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='X'){a[i][j].first=1;a[i][j].second=true;}
                else if(grid[i][j]=='Y'){a[i][j].first=-1;a[i][j].second=true;}
            }
        }
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                a[i][j].first+=a[i-1][j].first;a[i][j].second+=a[i-1][j].second;
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
               a[i][j].first+=a[i][j-1].first;a[i][j].second+=a[i][j-1].second;
            }
        }
        int sol=0;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                if(a[i][j].first==0&&a[i][j].second){sol++;}
            }
        }
        return sol;
    }
};
