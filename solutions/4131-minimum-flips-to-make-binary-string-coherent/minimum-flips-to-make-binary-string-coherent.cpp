class Solution {
public:
    int minFlips(string s) {
       int zeros=0;
       int lastzero=0;
       int cnt=0;
       for(char c:s){if(c=='0'){zeros++;lastzero=cnt;}cnt++;}
       if(zeros==0){return 0;}
       int firstzero=0;
       for(int i=0;i<s.size();i++){if(s[i]=='0'){firstzero=i;break;}}
       int ops=s.size()-zeros-1;
       if(s[0]=='1'&&s[s.size()-1]=='1'){
        return min(ops-1,zeros);
       }
       if(min(ops,zeros)<0){return 0;}
       return min(ops,zeros);
    }
};