class Solution {
public:
    int trap(vector<int>& height) {
        int lmax_index=0;
        int rmax_index=height.size()-1;
        int l_max=height[0];
        int r_max=height[height.size()-1];
        int ans=0;
        while(lmax_index!=rmax_index){
            if(r_max>l_max){
                lmax_index++;
                if(height[lmax_index]>l_max){
                    l_max=height[lmax_index];
                }
                else{ans+=(l_max-height[lmax_index]);}
            }
            else{
                rmax_index--;
                if(height[rmax_index]>r_max){
                    r_max=height[rmax_index];
                }
                else{ans+=(r_max-height[rmax_index]);}
            }
        }
        return ans;
    }
};
