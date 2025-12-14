class Solution {
public:
    int numberOfWays(string corridor) {
        int chairs=0;
        long long big=1000000007;
        for(int i=0;i<corridor.size();i++){if(corridor[i]=='S'){chairs++;}}
        if(chairs%2==1){return 0;}
        else if(chairs==0){return 0;}
        else{
            long long ans=1;
            int sim_plants=0;
            int chairs=0;
            for(int i=0;i<corridor.size();i++){ans=ans%big;
                if(corridor[i]=='S'&&chairs<2){chairs++;}
            else if(corridor[i]=='S'&&chairs==2){ans=ans*(sim_plants+1);chairs=1;sim_plants=0;}
            else if(corridor[i]=='P'&&chairs==2){sim_plants++;}}
            return ans;
        }

    }
};
