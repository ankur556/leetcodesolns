// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
int ans=n;
for(int i=0;i<n;i++){
    if(isBadVersion(n-i)){ans=n-i;}else{break;}}
return ans;;
    }
};
