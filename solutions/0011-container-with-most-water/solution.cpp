class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int sol=0;
        while(l<r){
        if(min(height[r],height[l])*(r-l)>sol){sol=min(height[r],height[l])*(r-l);}
        if(height[l]>height[r]){r--;}
        else if(height[l]<height[r]){l++;}
        else{l++;r--;}
        }
        return sol;
    }
};
