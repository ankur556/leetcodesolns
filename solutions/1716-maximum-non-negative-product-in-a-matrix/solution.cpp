class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        long long mod=1e9+7;
        vector<vector<vector<long long>>> helper;
        for(int i=0;i<grid.size();i++){
            vector<vector<long long>> a;
            helper.push_back(a);
            for(int j=0;j<grid[0].size();j++){
                vector<long long> g;
                helper[i].push_back(g);
                //int gd=grid[i][j];
                long long os=1;
                //helper[i][j].push_back(gd);
                helper[i][j].push_back(os);
                helper[i][j].push_back(os);
            }
        }
        if(grid.size()==0){return 1;}
        else{
            helper[0][0][0]=grid[0][0];
            helper[0][0][1]=grid[0][0];
            for(int i=1;i<grid.size();i++){helper[i][0][0]=grid[i][0]*helper[i-1][0][0];
            helper[i][0][1]=grid[i][0]*helper[i-1][0][1];}
            for(int j=1;j<grid[0].size();j++){
                helper[0][j][1]=helper[0][j-1][1]*grid[0][j];
                helper[0][j][0]=helper[0][j-1][1]*grid[0][j];
            }
            for(int i=1;i<grid.size();i++){
                for(int j=1;j<grid[0].size();j++){
                    long long mindp1=grid[i][j]*helper[i-1][j][0];//%mod;
                    long long mindp2=grid[i][j]*helper[i][j-1][0];//%mod;
                    long long maxdp1=grid[i][j]*helper[i][j-1][1];//%mod;
                    long long maxdp2=grid[i][j]*helper[i-1][j][1];//%mod;
                    helper[i][j][1]=max(maxdp1,max(maxdp2,max(mindp1,mindp2)));
                    helper[i][j][0]=min(maxdp1,min(maxdp2,min(mindp1,mindp2)));
                }
               
            }
            if( helper[helper.size()-1][helper[0].size()-1][1]<0){return -1;}
             return helper[helper.size()-1][helper[0].size()-1][1]%mod;
        }
    }
};
