class Solution {
public:
    int trap(vector<int>& height) {
        int sol=0;
        int l=0;
        int r=height.size()-1;
        int max_l=height[0];
        int max_r=height[height.size()-1];
        int h=min(max_l,max_r);
        
        while(l<r){
            max_l=max(height[l],max_l);
            max_r=max(height[r],max_r);
            h=min(max_l,max_r);
            if(height[r]>height[l]){sol+=(h-height[l]);l++;}
            else{sol+=(h-height[r]);r--;}
        }
        return sol;
    }
};
