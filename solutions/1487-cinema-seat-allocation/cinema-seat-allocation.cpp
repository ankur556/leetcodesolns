class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reserved_seats) {
        unordered_map<int,vector<bool>> map;
        vector<bool> init={{true},{true},{true}};
        for(int i=0;i<reserved_seats.size();i++){
            int k=reserved_seats[i][1];
            int row=reserved_seats[i][0];
            if(k==10){}
            else if(k==1){}
            else if(k==4||k==5){if(map[row].size()==0){map[row]=init;}
            map[row][1]=false;map[row][0]=false;}
            else if(k==6||k==7){
                if(map[row].size()==0){map[row]=init;}
                map[row][1]=false;map[row][2]=false;
            }
            else if(k==3||k==2){
                if(map[row].size()==0){map[row]=init;}
                map[row][0]=false;
            }
            else if(k==8||k==9){
                if(map[row].size()==0){map[row]=init;}
                map[row][2]=false;
            }
        }
        int sol=2*n;
        for(auto [a, b]: map){
            if(b[0]&&b[2]){}
            else if(b[0]||b[1]||b[2]){sol--;}
            else{sol-=2;}
        }
        return sol;
    }
};