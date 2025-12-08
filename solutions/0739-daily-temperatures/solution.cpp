class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> a;
        int count=0;
        vector<int> res(t.size(), 0);
        a.push(t.size()-1);
        for(int i=0;i<t.size();i++){
            while(!a.empty()&&t[a.top()]<=t[t.size()-i-1]){
                a.pop();
            }
            if(a.empty()){ res[ t.size()-i-1]= 0;}
            else{res[t.size()-i-1]=a.top()-(t.size()-i-1);}
            a.push(t.size()-i-1);
        }
        return res;
    }
};
