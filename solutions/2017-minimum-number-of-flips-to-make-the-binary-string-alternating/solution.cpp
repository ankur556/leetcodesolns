class Solution {
public:
    int minFlips(string s) {
        int of=0;
        int zf=0;
        int n=s.size();
        s+=s;
        int j=0;
        int soli=INT_MAX;
        for(int i=0;i<s.size();i++){
            j=i-n;
            if(i==n){soli=min(zf,of);}
            if(i%2==1){
                if(s[i]=='0'){zf++;}
                else{of++;}
            }
            else{
                if(s[i]=='1'){zf++;}
                else{of++;}
            }
            if(j>=0){
                if(j%2==1){
                if(s[j]=='0'){zf--;}
                else{of--;}
            }
            else{
                if(s[j]=='1'){zf--;}
                else{of--;}

            }
            if(of<soli){soli=of;}
            else if(zf<soli){soli=zf;}
            }
            }
        return soli;
    }


};
