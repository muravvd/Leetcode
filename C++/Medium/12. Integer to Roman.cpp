/*
Given an integer, convert it to a Roman numeral.

I	1
IV  4
V	5
IX  9
X	10
XL  40
L	50
XC  90
C	100
CD  400
D	500
CM  900
M	1000


*/

#include <iostream>
using namespace std;

/*
class Solution {        // 0ms   8mb
public:
    string intToRoman(int num) {
        string res = "";
        while (num > 0) {
            if (num >= 1000) {
                num -= 1000;
                res += "M";
            }
            else if (num >= 900) {
                num -= 900;
                res += "CM";
            }
            else if (num >= 500) {
                num -= 500;
                res += "D";
            }
            else if (num >= 400) {
                num -= 400;
                res += "CD";
            }
            else if (num >= 100) {
                num -= 100;
                res += "C";
            }
            else if (num >= 90) {
                num -= 90;
                res += "XC";
            }
            else if (num >= 50) {
                num -= 50;
                res += "L";
            }
            else if (num >= 40) {
                num -= 40;
                res += "XL";
            }
            else if (num >= 10) {
                num -= 10;
                res += "X";
            }
            else if (num >= 9) {
                num -= 9;
                res += "IX";
            }
            else if (num >= 5) {
                num -= 5;
                res += "V";
            }
            else if (num >= 4) {
                num -= 4;
                res += "IV";
            }
            else
                while (num > 0) {
                    res += "I";
                    num--;
                }
        }
        return res;
    }
};
*/
/*
class Solution {    // 4ms 10mb
public:
    string intToRoman(int num) {
        string one[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string ten[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hundred[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thousand[]={"","M","MM","MMM"};  // since the problem is limited by 3999
        return thousand[num/1000] + hundred[(num%1000)/100] + ten[(num%100)/10] + one[num%10];
    }
};
*/

class Solution {    // 1ms 10mb
    public:
    string intToRoman(int num) {
        string roman[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int value[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string result;
        int i = 0;
        while (num > 0) {
            if (num >= value[i]) {
                num -= value[i];
                result += roman[i];
            }
            else i++;
        }
        return result;
    }
};

int main() {
    Solution test;
    int num = 3749;
    cout << test.intToRoman(num) << endl;
    return 0;
}
