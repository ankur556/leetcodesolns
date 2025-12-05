class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gassum=0;
        int costsum=0;
        for(int i=0;i<gas.size();i++){
            gassum+=gas[i];
        }
        for(int i=0;i<cost.size();i++){
            costsum+=cost[i];
        }
        if(costsum>gassum){
            return -1;
        }
        else{
            int a=0;
            int b=0;
            int lastptr=0;
            for(int i=0;i<gas.size();i++){
                a+=gas[i];
                b+=cost[i];
                if(b>a){lastptr=i+1;a=0;b=0;}
            }
            return lastptr;
        }
    }
};
