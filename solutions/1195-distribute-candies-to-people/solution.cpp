class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> a(num_people);
        int i=0;
        int cur=1;
        while(candies>0){
            if(cur>candies){
                a[i]+=candies;
                candies=0;
            }
            else{
                a[i]+=cur;
                candies-=cur;
                cur++;
                i++;
                i%=num_people;
            }
        }
        return a;
    }
};
