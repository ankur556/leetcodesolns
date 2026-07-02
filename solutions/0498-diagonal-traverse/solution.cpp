class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //vector<int> a;
        pair<int,int> st={0,0};
        vector<pair<int,int>> dirs={{-1,1},{1,-1}};
        int vpush=0;
        vector<int> sol;
        while(true){
            if(vpush%2==0){
                //while(!(st.first>=0&&st.first<mat.size()&&st.second>=0&&st.second<mat[0].size())){st.first-=dirs[0].first;st.second-=dirs[0].second;}
                while(st.first>=0&&st.first<mat.size()&&st.second>=0&&st.second<mat[0].size()){sol.push_back(mat[st.first][st.second]);st.first+=dirs[0].first;st.second+=dirs[0].second;}
                st.first-=dirs[0].first;st.second-=dirs[0].second;
                if(st.first==mat.size()-1&&st.second==mat[0].size()-1){return sol;}
                if(st.second==mat[0].size()-1){
                st.first++;
                }
                else{
                st.second++;
                }
            }
            else{
                //while(!(st.first>=0&&st.first<mat.size()&&st.second>=0&&st.second<mat[0].size())){st.first-=dirs[1].first;st.second-=dirs[1].second;}
                while(st.first>=0&&st.first<mat.size()&&st.second>=0&&st.second<mat[0].size()){sol.push_back(mat[st.first][st.second]);st.first+=dirs[1].first;st.second+=dirs[1].second;}
                st.first-=dirs[1].first;st.second-=dirs[1].second;
                if(st.first==mat.size()-1&&st.second==mat[0].size()-1){return sol;}
                if(st.first==mat.size()-1){
                st.second++;
                }
                else{
                st.first++;
                }
            }
            vpush++;
        }
        return sol;
    }
};
