class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        vector<int> sol;
        for(int i=0;i<a.size();i++){
            if(a[i]>0){s.push(a[i]);}
            else{
                bool val=false;
                while(!s.empty()&&s.top()<=-a[i]){///equal case not dealt with yet
                    if(s.top()==(-a[i])){cout<<s.top()<<endl;s.pop();val=true;break;}
                    else{
                        s.pop();
                    }
                    }
                    if(s.empty()&&!val){sol.push_back(a[i]);}
                }
            }
            stack<int> t;
        while(!s.empty()){
            t.push(s.top());s.pop();
        }
        while(!t.empty()){
            sol.push_back(t.top());t.pop();
        }
        return sol;
    }
};