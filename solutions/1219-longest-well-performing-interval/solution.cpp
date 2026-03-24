class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> sum;
        int sumh=0;
        bool e=false;
        for(int i=0;i<hours.size();i++){
             sum.push_back(sumh);
            if(hours[i]>8){sumh++;e=true;}
            else{sumh--;}
        }
        sum.push_back(sumh);
        int sol=0;
        for(int i=0;i<hours.size();i++){
            for(int j=i;j<hours.size()+1;j++){
                if((j-i)>sol){if((sum[j]-sum[i])>0){sol=j-i;}}
            }
        }
       // if(sol==0&&e){return 1;}
        return sol;
    }
};
