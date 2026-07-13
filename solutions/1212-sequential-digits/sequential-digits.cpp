class Solution {
public:
    void helper(vector<int> &a ,int d){
        for(int i=d;i<9;i++){
            int k=0;
            for(int j=i-d+1;j<=i+1;j++){
                k*=10;
                k+=j;  
            }
            a.push_back(k);//cout<<k<<endl;
        }
    }
    vector<int> sequentialDigits(int low, int high) {
        int std=0;
        int endd=0;
        int lc=low;
        while(lc>0){lc/=10;std++;}
        lc=high;
        while(lc>0){lc/=10;endd++;}
        vector<int> sq;
        for(int i=std-1;i<endd;i++){
            vector<int> b;
            helper(b,i);
            for(int j=0;j<b.size();j++){
                if(b[j]<=high&&b[j]>=low){sq.push_back(b[j]);}
            }
        }
        return sq;
    }
};