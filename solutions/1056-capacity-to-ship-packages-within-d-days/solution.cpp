class Solution {
public:
    bool suffice(vector<int>& weights, int capacity, int days_limit) {
    int days_needed = 1; 
    int current_load = 0;

    for (int w : weights) {
        if (current_load + w > capacity) {
           
            days_needed++;
           
            current_load = w;
        } else {

            current_load += w;
        }
    }
   
    return days_needed <= days_limit;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int max;
        if(days>weights.size()){
             max=weights[0];
            for(int w: weights){if(w>max){max=w;}}
            return max;
        }
        else{
            int sol=0;
            int sum=0;
            max=weights[0];
            for(int w: weights){if(w>max){max=w;}sum+=w;}
            sol=max;
            int left=sol;
            int right=sum;
            
            while(right>=left){
                sol=left+(right-left)/2;
                if(suffice(weights,sol,days)){right=sol-1;}
                else{left=sol+1;}
            }
            return left;
        }
    }
};
