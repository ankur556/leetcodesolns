class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>map1;
       for(int i : nums1){map1[i]++;}
        unordered_map<int,int>map2;
       for(int i : nums2){map2[i]++;}
       int k=0;
       vector<int> sol;
       for(int i : nums2){k=min(map1[i],map2[i]);
       map1[i]=0;map2[i]=0;
       while(k--){
        sol.push_back(i);
       }
       }
       return sol;
    }
};
