class Solution {
public:
    int minPartitions(string n) {
        vector<int> help;
        int max=0;
        for( char i:n){if(i>max){max=i;}}
        //int max=0;
        //for(int i: help){if(i>max){max=i;}}
        return max-48;
    }
};
