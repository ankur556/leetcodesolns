class Solution {
public:
    int maxBottlesDrunk(int numbottles, int numExchange) {
        int ans=0;
        int empty=0;
        while(numbottles>0||empty>0){
            ans+=numbottles;
            
            empty=empty+numbottles;
            numbottles=0;
            while(empty>=numExchange){numbottles++;empty=empty-numExchange;numExchange++;}
            if(numbottles==0&&empty<numExchange){return ans;}
        }
        return ans;
    }
};
