class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a;
        for(int i=0;i<nums2.size();i++){a[nums2[i]]=i;}
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty()&&nums2[i]>s.top()){s.pop();}
            if(s.empty()){s.push(nums2[i]);nums2[i]=-1;}
            else{int k=s.top();s.push(nums2[i]);nums2[i]=k;}
        }
        vector<int> sol;
        for(int i=0;i<nums1.size();i++){
            sol.push_back(nums2[a[nums1[i]]]);
        }
        return sol;
    }
};