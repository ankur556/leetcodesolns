class Solution {
public:
    int integerBreak(int n) {
        if(n==2){return 1;}
        else if(n==3){return 2;}
        int noof3s=0;
        int noof2s=0;
        while(n>4){n=n-3;noof3s++;}
        if(n==4){noof2s=2;}
        else if(n==3){noof3s++;}
        else if(n==2){noof2s++;}
        int ans=1;
        for(int i=0;i<noof3s;i++){
            ans=ans*3;
        }
        for(int i=0;i<noof2s;i++){
            ans=ans*2;
        }
        return ans;
    }
};
