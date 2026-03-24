class Solution {
public:
    string convertToTitle(int col) {
    string sol;
    while(col>0){col--;sol.push_back(col%26+'A');col/=26;}
    for(int i=0;i<sol.size()/2;i++){swap(sol[i],sol[sol.size()-1-i]);}
    return sol;
    }
};
