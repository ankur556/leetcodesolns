class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int count=0;
        int fruit1=fruits[0];
        int fruit2=fruits[0];
        int last_idx1=0;
        int last_idx2=0;
        int i=0;
        //while(fruit2==fruits[0]&&i<fruits.size()){
        //    fruit2=fruits[i];i++;last_idx2++;
        // }
        //last_idx1=last_idx2-1;
        if(i>=fruits.size()){return fruits.size();}
        else{
            int sol=i+1;
            int curr=i+1;
            for(int j=i+1;j<fruits.size();j++){
                if(fruits[j]!=fruit1&&fruits[j]!=fruit2){
                if(fruit1==fruit2){
                    curr=j+1;fruit2=fruits[j];last_idx2=j;
                }
                else if(last_idx2>last_idx1){
                    curr=j-last_idx1;
                    fruit1=fruits[j];
                    last_idx1=j;
                }
                else{
                    curr=j-last_idx2;
                    fruit2=fruits[j];
                    last_idx2=j;
                }
                }
                else if(fruits[j]==fruit1){curr++;last_idx1=j;}
                else{curr++;last_idx2=j;}
                if(curr>sol){sol=curr;}
            }
            return sol;
        }
    }
};
