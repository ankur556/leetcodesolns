class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sol=0;
        if(n==0){return true;}
        if(flowerbed.size()==1){return (flowerbed[0]==0&&n==1);}
        if(flowerbed[0]==0&&flowerbed[1]==0){sol++;flowerbed[0]=1;}
        if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0){sol++;flowerbed[flowerbed.size()-1]=1;}
        for(int i=1;i<flowerbed.size();i++){
            if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0){flowerbed[i]=1;sol++;}
        }
        return (sol>=n);
    }
};
