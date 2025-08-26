class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int big=matrix[0].size()-1;
        int smoll=0;
        int mid=0;
        for(int i=0;i<matrix.size();i++){
            big=matrix[0].size()-1;
            smoll=0;
            while(smoll<=big){
                mid=smoll+(big-smoll)/2;
                if(target==matrix[i][mid]){return true;}
                else if(target<matrix[i][mid]){big=mid-1;}
                else if(target>matrix[i][mid]){smoll=mid+1;}
                else if(big==smoll+1&&matrix[i][big]!=target&&matrix[i][smoll]!=target){
                    break;
                }
                else if(big==smoll&&matrix[i][big]!=target&&matrix[i][smoll]!=target){
                    break;
                }
            }
        }
        return false;
    }
};
