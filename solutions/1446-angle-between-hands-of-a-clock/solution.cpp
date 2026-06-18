class Solution {
public:
    double angleClock(int hour, int minutes) {
        double sol=0;
        hour%=12;
        double ang1=((double)hour+(double)minutes/60)*360/12;
        double ang2=(double)minutes*360/60;
        //ang1%=360;
        //ang2%=360;
        sol=abs(ang1-ang2);
        if(sol>180){sol=360-sol;}
        return sol;
    }
};
