class Solution {
public:
    bool isval(int a,int b,int c){
        return pow(a,b)>=c;
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if(buckets==1){return 0;}
        int r=minutesToTest/minutesToDie+1;
        int p=1;
        while(!isval(r,p,buckets)){p++;}
        return p;
    }
};
