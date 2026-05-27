class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> a;
        for(int i: arr){a.push_back(i);if(i==0){a.push_back(i);}}
        for(int i=0;i<arr.size();i++){
            arr[i]=a[i];
        }
        //return arr;
    }
};
