class Solution{
    public:
    int totalMoney(int n){
        int r=n/7;
        int k=28;
        int ans=0;
        n=n%7;
for(int i=0;i<r;i++){
ans+=k;
k+=7;
}
for(int i=0;i<n+1;i++){
    ans+=(i+r);
}
        return ans-r;
    }
};
