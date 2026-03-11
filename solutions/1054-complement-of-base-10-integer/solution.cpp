class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){return 1;}
       vector<int> a;
       while(n>0){a.push_back(n%2);n/=2;} 
       int sol=0;
       for(int i=0;i<a.size();i++){if(a[i]==1){a[i]=0;}else{a[i]=1;}}
       for(int i=a.size()-1;i>=0;i--){sol*=2;sol+=a[i];}
       return sol;
    }
};
