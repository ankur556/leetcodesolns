class Solution {
public:
    int wav(int t){
        string a=to_string(t);
        int res=0;
        for(int i=1;i<a.size()-1;i++){
            if(a[i+1]>a[i]&&a[i]<a[i-1]){res++;}
            else if(a[i+1]<a[i]&&a[i]>a[i-1]){res++;}
        }
        return res;
    }
    int totalWaviness(int num1, int num2) {
        int sol=0;
        for(int i=num1;i<=num2;i++){
            sol+=wav(i);
        }
        return sol;
    }
};
