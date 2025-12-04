class Solution {
public:
    int countCollisions(string d) {
        int c=0;
        bool right=false;
        bool left=false;
        for(int i=0;i<d.size();i++){
            if(left==false&&(d[i]=='S'||d[i]=='R')){left=true;}
            else if(left==true&&d[i]=='L'){c++;}
        }
        for(int i=0;i<d.size()+1;i++){
            if(right==false&&(d[d.size()-i]=='S'||d[d.size()-i]=='L')){right=true;}
            else if(right==true&&d[d.size()-i]=='R'){c++;}
        }
        return c;
    }
};
