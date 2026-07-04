class StockSpanner {
public:
stack<pair<int,int>> og;
int idx;
    StockSpanner() {
        idx=0;
    }
    
    int next(int price) {
        idx++;
        if(og.empty()){og.push({price,idx});return 1;}
        else{
            int sol=1;
            stack<int> temp;
            //temp=og;
            while(!og.empty()&&og.top().first<=price){sol=idx-og.top().second+1;og.pop();}
            if(og.empty()){sol=idx;}
            else{sol=idx-og.top().second;}
            og.push({price,idx});
            return sol;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
