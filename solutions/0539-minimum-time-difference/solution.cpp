class Solution {
public:
    int diff(string b,string a){
        int val=(((a[0]-b[0])*10)+a[1]-b[1])*60+(a[3]-b[3])*10+a[4]-b[4];
        val=-val;
        int mod=24*60;
        val=min(val,abs(mod-val));
        return val;
    }
    int findMinDifference(vector<string>& time) {
    sort(time.begin(),time.end());
    int mini=1e6;
    for(int i=1;i<time.size();i++){
        if(diff(time[i],time[i-1])<mini){mini=diff(time[i],time[i-1]);}
    }
    return min(mini,diff(time[time.size()-1],time[0]));
    }
};
