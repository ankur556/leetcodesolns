class Solution {
public:
    int bin1(int a){
        int g=a;int sol=0;
        while(g>0){
            if(g%2==1){sol++;}
            g=g/2;
        }
        return sol;
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> alm(arr.size());
        int k=0;
        for(int i=0;i<arr.size();i++){
            k=bin1(arr[i]);
            alm[i].first=k;
            alm[i].second=arr[i];
        }
        sort(alm.begin(),alm.end());
        vector<int> sol;
        for(int i=0;i<arr.size();i++){
            sol.push_back(alm[i].second);
        }
        return sol;
    }
};
