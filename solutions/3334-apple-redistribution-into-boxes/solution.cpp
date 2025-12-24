class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end());
        int sum=0;
        for(int a: apple){sum+=a;}
        int sol=0;
        for(int i=capacity.size()-1;i>=0;i--){
            sum-=capacity[i];
            sol++;
            if(sum<=0){break;}
        }
        return sol;
    }
};
