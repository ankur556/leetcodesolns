class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& images) {
        for(int i=0;i<images.size();i++){
            for(int j=0;j<images[i].size();j++){
                if(images[i][j]==0){images[i][j]=1;}
                else{images[i][j]=0;}
            }
        }
        for(int i=0;i<images.size();i++){
            for(int j=0;j<images[i].size()/2;j++){
                swap(images[i][j],images[i][images[i].size()-1-j]);
            }
        }
        return images;
    }
};
