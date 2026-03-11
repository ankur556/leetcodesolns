class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> a;
        unordered_map<string,int> map;
        for(int i=0;i<list1.size();i++){map[list1[i]]=i+1;}
        int mins=list1.size()+list2.size();
        
        for(int i=0;i<list2.size();i++){if(map[list2[i]]>0){if(map[list2[i]]+i<mins){mins=i+map[list2[i]];}
        }}
        vector<string> sol;
        for(int i=0;i<list2.size();i++){if(map[list2[i]]>0){if(map[list2[i]]+i==mins){sol.push_back(list2[i]);}
        }}
        return sol;
    }
};
