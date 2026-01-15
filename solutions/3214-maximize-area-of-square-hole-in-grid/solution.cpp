class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int len=1;
        int width=1;
        int curr=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        if(hBars.size()>0){len=2;curr=2;}
        if(vBars.size()>0){width=2;curr=2;}
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i]+1==hBars[i+1]){curr++;}
            else{curr=2;}
            len=max(len,curr);
        }
        curr=2;
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i]+1==vBars[i+1]){curr++;}
            else{curr=2;}
            width=max(curr,width);
        }
        int l=min(width,len);
        return l*l;
    }
};
