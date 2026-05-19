class Solution {
public:
    string convertToBase7(int num) {
        if(num==0){return "0";}
       vector<int> a;
       bool neg=false;
       if(num<0){num=-num;neg=true;}
       while(num>0){
        a.push_back(num%7);
        num/=7;
       } 
       for(int i:a){cout<<i<<endl;  }

       string s;
       for(int i=0;i<a.size();i++){
        s.push_back(a[i]+'0');
       }
       if(neg){s.push_back('-');}
       for(int i=0;i<(s.size())/2;i++){
        swap(s[i],s[s.size()-1-i]);
       }
       return s;     
    }
};
