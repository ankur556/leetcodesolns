class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.size()!=s2.size()){return false;}
        unordered_map<char,int> even;
        unordered_map<char,int> odd;
        for(int i=0;i<s1.size();i++){
            if(i%2==1){odd[s1[i]]++;}
            else{even[s1[i]]++;}
        }
        for(int i=0;i<s2.size();i++){
            if(i%2==1){odd[s2[i]]--;}
            else{even[s2[i]]--;}
        }  
        for(int i=0;i<s2.size();i++){
            if(i%2==1){if(odd[s2[i]]!=0){return false;}}
            else{if(even[s2[i]]!=0){return false;}}
        }          
        return true;
    }
};
