class Solution {
public:
    int maximum69Number (int num) {
        vector<int> a;
        int temp=num;
        while(temp!=0){
            a.push_back(temp%10);
            temp=temp/10;
        }
    int index=-1;
    for(int i =0;i<a.size();i++){
        if(a[i]==6){index=i;}
        else{continue;}
    }
    if(index==-1){return num;}
    else{return ((num)+(3*(pow(10,index))));}
    }
};
