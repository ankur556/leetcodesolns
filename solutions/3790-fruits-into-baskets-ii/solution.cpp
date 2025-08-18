class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed =0;
        if(fruits.size()==1){
          if (fruits[0] > *max_element(baskets.begin(), baskets.end() )) {
          return 1;
          } else {
          return 0;
          }
        }
        else{
            
            for(int j=0;j<fruits.size();j++){
                for(int i=0;i<baskets.size();i++){
                if(baskets[i]>=fruits[j]){
                    baskets[i]=0;
                    
                    placed++;
                    break;
                }
            }
        }
        return fruits.size()-placed;
        }
    }
};
