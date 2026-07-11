class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
       // if(t.size()>s.size()+1){return}
        if(s.size()<=1){
            return true;
        }
        if(t.size()<s.size()){return false;}
        vector<int> pre;
        vector<int> post;
        int st=0;
        int cnt=0;
        for(int i=0;i<t.size();i++){
            if(t[i]==s[st]){st++;cnt++;}
            if(cnt==s.size()-1&&i!=t.size()-1){return true;}
            pre.push_back(cnt);
        }
        st=s.size()-1;
        cnt=0;
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]==s[st]){st--;cnt++;}
            if(cnt==s.size()-1&&i!=0){return true;}
            post.push_back(cnt);
        }
        for(int i=0;i<(post.size()/2);i++){
            swap(post[i],post[post.size()-i-1]);
        }
        //if(post[0]>=s.size()-1||pre[pre.size()-2]>=s.size()-1){return true;}
        for(int i=1;i<t.size()-1;i++){
            if(pre[i-1]+post[i+1]>=s.size()-1){return true;}
        }
        return false;
    }
};
