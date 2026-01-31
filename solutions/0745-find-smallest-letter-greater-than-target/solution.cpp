class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int k=0;
for(int i=0;i<letters.size();i++){
    if(int(letters[i])<=int(target)){continue;}
    else{k=i;break;}
}
        if(k<letters.size()){return letters[k];}
        else{return letters[0];}
    }
};
