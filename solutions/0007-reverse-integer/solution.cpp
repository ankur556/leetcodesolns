class Solution {
public:
    int reverse(int r) {
        if(r==-2147483648){return 0;}
        vector<int> a;
        bool pos=true;
        if(r<0){pos=false;}
        long long x=abs(r);
        while(x>0){
            a.push_back(x%10);
            x=x/10;
        }
        long long sol=0;
        for(int i=0;i<a.size();i++){
            sol=sol*10;sol+=a[i];
        }
        if (pos && sol > INT_MAX) {return 0;}
            if (!pos && -sol < INT_MIN){ return 0;
        }
        if(pos){return (int)sol;}
        else{return (int)(-sol);}
    }
};
