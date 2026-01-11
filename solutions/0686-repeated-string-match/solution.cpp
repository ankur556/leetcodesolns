class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        unordered_set<char> unique_chars;
        for(char c : a) unique_chars.insert(c);
        for(char c : b) {
            if(unique_chars.find(c) == unique_chars.end()) return -1;
        }

        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(char c: a) map1[c]++;
        for(char c: b) map2[c]++;
        
        int max_val = 1;
        for(char c: a){
             int val = (map2[c] - map1[c]) / map1[c] + 1;
             if(val > max_val) max_val = val;
        }
        
        string temp = "";
        for(int i=0; i < max_val; i++) temp += a;
        
        if(temp.find(b) != string::npos) return max_val;
        
        temp += a;
        if(temp.find(b) != string::npos) return max_val + 1;
        
        return -1;
    }
};
