class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> sol;
        int n1ptr=0;int n2ptr=0;
        while(n1ptr<m||n2ptr<n){
            if(n1ptr==m){sol.push_back(nums2[n2ptr]);n2ptr++;}
            else if(n2ptr==n){sol.push_back(nums1[n1ptr]);n1ptr++;}
            else if(nums1[n1ptr]<nums2[n2ptr]){sol.push_back(nums1[n1ptr]);n1ptr++;}
            else{sol.push_back(nums2[n2ptr]);n2ptr++;}
        }
        nums1=sol;
    }
};
