class Solution {
public:
    string intToRoman(int num) {
        string a = "";
        while(num > 0) {
            if(num >= 1000) {
                a += "M";
                num -= 1000;
            } else if(num >= 900) {
                a += "CM";
                num -= 900;
            } else if(num >= 500) {
                a += "D";
                num -= 500;
            } else if(num >= 400) {
                a += "CD";
                num -= 400;
            } else if(num >= 100) {
                a += "C";
                num -= 100;
            } else if(num >= 90) {
                a += "XC";
                num -= 90;
            } else if(num >= 50) {
                a += "L";
                num -= 50;
            } else if(num >= 40) {
                a += "XL";
                num -= 40;
            } else if(num >= 10) {
                a += "X";
                num -= 10;
            } else if(num >= 9) {
                a += "IX";
                num -= 9;
            } else if(num >= 5) {
                a += "V";
                num -= 5;
            } else if(num >= 4) {
                a += "IV";
                num -= 4;
            } else if(num >= 1) {
                a += "I";
                num -= 1;
            }
        }
        return a;
    }
};

