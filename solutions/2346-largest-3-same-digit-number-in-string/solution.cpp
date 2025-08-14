class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int>a ={-1};
    for(int i=0;i<num.size()-2;i++){
        if(num[i]==num[i+1]&&num[i+1]==num[i+2]){
            a.push_back(num[i]);
        }

    }
    char max='/';
    for(int i=0;i<a.size();i++){
        if(max<a[i]){max=a[i];}
    }
    if(max=='/'){
        return "";
    }
    else {return string(3,max);};
}};
