class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sol=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(neededTime[0]);
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                pq.push(neededTime[i]);
            }
            else{
               while(pq.size()>1){
                sol+=pq.top();
                pq.pop();
               } 
               pq.pop();
               pq.push(neededTime[i]);   
            }
        }
        while(pq.size()>1){
        sol+=pq.top();
        pq.pop();
        }
        return sol;
    }
};