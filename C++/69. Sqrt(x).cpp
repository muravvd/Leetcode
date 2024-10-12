/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

0 <= x <= 2^31 - 1
*/

#include <cmath>
#include <iostream>
using namespace std;

/*class Solution {         // 15ms
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long long y = 2;
        while (y * y < x)
            y++;
        if (y * y > x)
            y--;
        return y;
    }
};*/

class Solution {        // 0ms
public:
    int mySqrt(int x) {
        int bottom = 0, top = 46340, mid = 23170; // 46340 is the largest floored sqrt for 0 <= x <= 2^31 - 1
        while (bottom <= top) {
            if (mid * mid == x)
                return mid;
            if (mid * mid < x) {
                bottom = mid+1;
                mid = bottom + (top-bottom)/2;
                continue;
            }
            if (mid * mid > x) {
                top = mid-1;
                mid = bottom + (top-bottom)/2;
            }
        }
        return top;
        }
    };

    int main() {
        Solution test;
        int a = 2147483647; // 46340
        int b = 808909662;
        cout << test.mySqrt(b);
        return 0;
    }