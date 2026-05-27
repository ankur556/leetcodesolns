class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26,0);
        vector<int> high(26,0);
        int cnt=0;
        for(int i=0;i<word.size();i++){
            if(word[i]-'a'>=0&&word[i]-'a'<26){low[word[i]-'a']=i+1;}
        }
        for(int i=0;i<word.size();i++){
            if(word[i]-'A'>=0&&word[i]-'A'<26){
                if(low[word[i]-'A']<i+1&&high[word[i]-'A']==0&&low[word[i]-'A']!=0){cnt++;high[word[i]-'A']=i+1;}
                else if(high[word[i]-'A']==0){high[word[i]-'A']=i+1;}
            }
        }
        return cnt;
    }
};
