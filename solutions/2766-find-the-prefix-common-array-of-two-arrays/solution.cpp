class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> a_ele;
        unordered_map<int,int> b_ele;
        int cnt=0;
        vector<int> sol;
        for(int i=0;i<A.size();i++){
        a_ele[A[i]]++;
        if(a_ele[A[i]]<=b_ele[A[i]]){cnt++;}
        b_ele[B[i]]++;
        if(b_ele[B[i]]<=a_ele[B[i]]){cnt++;}
        sol.push_back(cnt);
    }
    return sol;
     
    
    }
   

};
