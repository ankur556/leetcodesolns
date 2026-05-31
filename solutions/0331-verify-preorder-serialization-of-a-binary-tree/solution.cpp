class Solution {
public:
    bool isValidSerialization(string p) {
        vector<string>preorder;
        for(int i=0;i<p.size();i++){
            if(p[i]==','){}
            else{
                string b;
                while(i<p.size()&&p[i]!=','){
                    b.push_back(p[i]);
                    i++;
                }
                preorder.push_back(b);
            }
        }
        int cnt=1;
        int cnt2=0;
        for(auto c: preorder){
            if(c!=","){
            cnt--;
            if(cnt<0){return false;}
            if(c!="#"){cnt+=2;}
            }
            cnt2++;
        }
        return cnt==0;
    }
};
