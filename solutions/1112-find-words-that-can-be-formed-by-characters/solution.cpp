class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       unordered_map<char,int> a;
       for(char c: chars){a[c]++;}
       unordered_map<char,int> b;
       int sol=0;
       bool t=true;
       for(string s: words){b=a;t=true;
        for(int i=0;i<s.size();i++){
            if(b[s[i]]>0){b[s[i]]--;}
            else{t=false;break;}
        }
        if(t){sol+=s.size();}
       } 
       return sol;
    }
};
