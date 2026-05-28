class Solution {
public:
    bool canTransform(string start, string result) {

            
            vector<pair<char,int>> eq;
            for(int i=0;i<start.size();i++){
                if(start[i]=='X'){}else{eq.push_back({start[i],i});}
            }
            int eqptr=0;
            for(int i=0;i<result.size();i++){
                if(result[i]!='X'){
                    if(eqptr>=eq.size()){return false;}
                    if(result[i]!=eq[eqptr].first){return false;}
                    else{if(result[i]=='R'){if(eq[eqptr].second<=i){eqptr++;}else{return false;}}
                    else{if(eq[eqptr].second>=i){eqptr++;}else{return false;}}
                    }
                }
            }
            return eqptr==eq.size();
        
    }
};
