class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>> a(board.size(),vector<int>(board[0].size()));
        queue<pair<int,int>> q;
       for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){q.push({i,0});;}
       }
        for(int i=0;i<board.size();i++){
            if(board[i][board[0].size()-1]=='O'){q.push({i,board[0].size()-1});}
       }
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O'){q.push({0,i});}
       }  
        for(int i=0;i<board[0].size();i++){
            if(board[board.size()-1][i]=='O'){q.push({board.size()-1,i});}
       }  
       vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        if(a[r][c]==1){}
        else{
            a[r][c]=1;
            for(auto dir:dirs){
                int rc=r+dir.first;
                int cc=c+dir.second;
                if(cc>=0&&cc<a[0].size()&&rc>=0&&rc<a.size()){
                    if(board[rc][cc]=='O'){q.push({rc,cc});}
                }
            }
        }
       
        }
         for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(a[i][j]==1){board[i][j]='O';}
                else{board[i][j]='X';}
            }
    }
    }
};
