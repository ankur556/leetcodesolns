class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // we have to get the higest dist first then we can measure its time and cheack how many can reach till end before it and if they can reach end before then they can join the fleet
        int cur=0;
        double cur_time=0;
        int sol=0;
        vector<pair<int,int>> pos_speed;
        for(int i=0;i<position.size();i++){
            pos_speed.push_back({position[i],speed[i]});
        }
        // eval time of the last then go cheack how many can be paired from there then put the count to 0
        sort(pos_speed.rbegin(),pos_speed.rend());
        for(int i=0;i<pos_speed.size();i++){
            if(cur_time==0.0){
                cur_time=(double)(target-pos_speed[i].first)/pos_speed[i].second;
                cur=1;
                sol++;
            }
            else{
                if(cur_time>=(double)(target-pos_speed[i].first)/pos_speed[i].second){cur++;}
                else{cur_time=(double)(target-pos_speed[i].first)/pos_speed[i].second;cur=1;sol++;}
            }
        
        }
        return sol;
    }
};