class Solution {
public:
    int compress(vector<char>& chars) {
      int sol=0;
      int cur=1;
      vector<char> a;
      for(int i=1;i<chars.size();i++){
        if(chars[i]==chars[i-1]){cur++;}
        else if(cur==1){sol++;a.push_back(chars[i-1]);}//a.push_back('1');}
        else{sol+=(1+to_string(cur).size());a.push_back(chars[i-1]);for(char c: to_string(cur)){a.push_back(c);}cur=1;}
      }
      a.push_back(chars[chars.size()-1]);sol+=1;
      if(cur!=1){for(char c: to_string(cur)){a.push_back(c);}sol+=to_string(cur).size();}  
      chars=a;
      return sol;
    }
};
