class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int> odd;
        unordered_map<char,int> even;
        for(int i=0;i<s2.size();i++){
            if(i%2==1){odd[s2[i]]++;}
            else{even[s2[i]]++;}
        }
        for(int i=0;i<s1.size();i++){
            if(i%2==1){if(odd[s1[i]]==0){return false;}odd[s1[i]]--;}
            else{if(even[s1[i]]==0){return false;}even[s1[i]]--;}
        }
        for(int i=0;i<s1.size();i++){
            if(i%2==1){if(odd[s1[i]]!=0){return false;}}
            else{if(even[s1[i]]!=0){return false;}}
        }
        return true;
    }
};
