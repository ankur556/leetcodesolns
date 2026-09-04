class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> sol;
        stack<int> s;
        for(int i : asteroids){
            if(i>0){s.push(i);}
            else{
                while(!s.empty()&&s.top()<-i){s.pop();}
                if(s.empty()){sol.push_back(i);}
                else if(s.top()==-i){s.pop();}
            }
        }
        stack<int> s2;
        while(!s.empty()){s2.push(s.top());s.pop();}
        while(!s2.empty()){sol.push_back(s2.top());s2.pop();}
        return sol;
    }
};