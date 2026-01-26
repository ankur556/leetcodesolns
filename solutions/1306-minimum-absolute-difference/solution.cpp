class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>>sol;
        if(arr.size()<2){return sol;}
        else if(arr.size()==2){sol.push_back(arr);return sol;}
        else{
            int min_diff=arr[1]-arr[0];
            for(int i=0;i<arr.size()-1;i++){
                if(arr[i+1]-arr[i]<min_diff){min_diff=arr[i+1]-arr[i];}
            }
            for(int i=0;i<arr.size()-1;i++){
                if(arr[i+1]-arr[i]==min_diff){sol.push_back({arr[i],arr[i+1]});}
            }
            return sol;
        }

    }
};
