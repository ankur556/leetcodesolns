class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int sol=0;
       int l=0;
       int r=arr.size()-1;
       while(l<=r){
        sol=l+(r-l)/2;
        if(arr[sol+1]>arr[sol]){l=sol+1;}
        else{r=sol-1;}
       }
       return l;
    }
};
