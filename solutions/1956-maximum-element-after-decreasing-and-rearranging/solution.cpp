class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int cur=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(arr[i]>cur){cur++;}
        }
        if(cur>arr.size()){return cur-1;}
        return cur;
    }
};
