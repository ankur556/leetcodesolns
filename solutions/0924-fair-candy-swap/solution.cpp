class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        int suma=0;int sumb=0;
        for(int i:a){suma+=i;}
        for(int i:b){sumb+=i;}
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int aptr=a.size()-1;int bptr=b.size()-1;
        vector<int> sol;
        while(aptr>=0&&bptr>=0){
            if(suma+b[bptr]-a[aptr]==sumb+a[aptr]-b[bptr]){sol.push_back(a[aptr]);sol.push_back(b[bptr]);return sol;}
            else if(suma+b[bptr]-a[aptr]>sumb+a[aptr]-b[bptr]){bptr--;}
            else{aptr--;}
        }
        return sol;
    }
};
