class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> a;
        int er=0;
        for(int i=0;i<grid.size();i++){
            er=0;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){er=j;}
            }
            a.push_back(er);
        }
        int swaps=0;
        // for(int j=0;j<a.size();j++){
        // for(int i=0;i<a.size()-1;i++){
        //     if(a[i+1]<a[i]&&a[i]>i){swaps++;swap(a[i],a[i+1]);}
        // }}
        // bool valid=true;
        // for(int i=0;i<a.size();i++){
        //     if(a[i]>i){return -1;}
        // }
        int k=0;
        for(int i=0;i<a.size();i++){
            k=i;
            while(k<a.size()&&a[k]>i){k++;}
            if(k==a.size()){
                return -1;
            }
            else{for(int r=k;r>i;r--){swaps++;swap(a[r],a[r-1]);}}
        }
        return swaps;
    }
};
