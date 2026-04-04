class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int st_i=0;int st_j=0;int c=encodedText.size()/rows;
        vector<string> a(rows);
        for(int i=0;i<rows;i++){
            for(int j=0;j<c;j++){
                a[i].push_back(encodedText[i*c+j]);
            }
        }
        bool v=false;
        //for(int i=0;i<a.size();i++){
           // for(int j=0;j<a[0].size();j++){
            //    if(a[i][j]!=' '){st_i=i;st_j=j;v=true;break;}
           // }
           // if(v){break;}
       // }
        //st_j=st_j-st_i;st_i=0;
        string sol;
        int dia_i=st_i;int dia_j=st_j;
        while(dia_j!=a[0].size()){
            if(st_i==a.size()-1){sol.push_back(a[st_i][st_j]);st_i=0;st_j=++dia_j;}
            else if(st_j==a[0].size()-1){sol.push_back(a[st_i][st_j]);st_i=0;st_j=++dia_j;}
            else{sol.push_back(a[st_i][st_j]);st_i++;st_j++;}
        }
        string acc_sol;
        if(sol.size()==0){return sol;}
        int l=0;int p=sol.size()-1;
        //while(sol[l]==' '){l++;}
        //while(sol[p]==' '){p--;}
        while(!sol.empty() && sol.back() == ' '){
            sol.pop_back();
        }
        
        return sol;
    }

};
