class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
       unordered_map<int,int> map;
       for(int i: bulbs){map[i]++;}
       vector<int> a;
       for(int i=0;i<=100;i++){if(map[i]%2==0){}else{a.push_back(i);map[i]=0;}}
    return a;
    }
};
