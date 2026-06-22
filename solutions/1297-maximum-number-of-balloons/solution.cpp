class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> map;
        int sol=1e9;
        string b="balon";
        for(char c:text){map[c]++;}//cout<<c<<endl;}
        for(auto c:b){
        if(c=='l'||c=='o'){if(map[c]/2<sol){sol=map[c]/2;}}//cout<<sol<<endl;}}
        else if(map[c]<sol){sol=map[c];}//cout<<sol<<endl;}
        }
        return sol;
    }
};
