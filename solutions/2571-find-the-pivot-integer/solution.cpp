class Solution {
public:
    int pivotInteger(int n) {
        int sum=((n)*(n+1))/2;
int curr=0;
for(int i=0;i<n+1;i++){curr+=i;
if(2*curr==sum+i){return i;}}
        return -1;
    }
};
