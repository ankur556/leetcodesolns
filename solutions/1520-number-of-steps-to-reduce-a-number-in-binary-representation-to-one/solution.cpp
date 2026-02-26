class Solution {
public:
    void add(string & s){
        int k=s.size()-1;
        int ones=0;
            while(k>=0&&s[k]=='1'){s[k]='0';k--;ones++;}
        if(ones==s.size()){
            string d;
            d.push_back('1');
            for(int i=0;i<s.size();i++){
                d.push_back(s[i]);
            }
            s=d;
        }
        else{s[k]='1';}
        return;
    }
    int numSteps(string s) {
        int sol=0;
        while(s!="1"){
            sol++;
            string a;
            if(s[s.size()-1]=='0'){
                for(int i=0;i<s.size()-1;i++){
                    a.push_back(s[i]);
                }
                s=a;
            }
            else{
                add(s);
            }
        }
        return sol;
    }
};
