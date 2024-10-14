/*
Given two binary strings a and b, return their sum as a binary string.
*/


#include <algorithm>
#include <iostream>
#include <bits/ranges_algo.h>
using namespace std;

/*unsigned long long toDecimal(string s) {
    unsigned long long a = 0, cur = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1')
            a += cur;
        cur *= 2;
    }
    return a;
}

string toBinary(unsigned long long num) {
    if (num == 0)
        return "0";
    string binary = "";
    while (num > 0) {
        int remainder = num % 2;
        binary = to_string(remainder) + binary;
        num = num / 2;
    }
    return binary;
}*/

/*class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        return toBinary(toDecimal(a) + toDecimal(b));
    }
};*/

/*int main() {
    Solution test;
    string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101", b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    //cout << test.addBinary(a, b);
    cout << toDecimal(a) << endl;
    cout << toDecimal(b) << endl;
    return 0;
}*/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;
        int carry = 0;
        string res = "";
        int as = a.size() - 1; // counter is faster than s.size()
        int bs = b.size() - 1;
        while (as >= 0 && bs >= 0) {
            if (a[as] == '0' && b[bs] == '0') {
                if (carry > 0) {
                    res += '1';
                    carry--;
                    as--;
                    bs--;
                    continue;
                }
                res += '0';
                as--;
                bs--;
                continue;
            }
            if (a[as] == '1' && b[bs] == '1') {
                if (carry > 0) {
                    res += '1';
                    as--;
                    bs--;
                    continue;
                }
                res += '0';
                carry++;
                as--;
                bs--;
                continue;
            }
            if (carry > 0) {
                // one of a || b is 1 and the other is 0
                res += '0';
                as--;
                bs--;
                continue;
            }
            res += '1';
            as--;
            bs--;
        }

        while (as >= 0) {
            if (carry > 0) {
                if (a[as] == '1') {
                    res += '0';
                    as--;
                    continue;
                }
                res += '1';
                as--;
                carry--;
                continue;
            }
            res += a[as];
            as--;
        }


        while (bs >= 0) {
            if (carry > 0) {
                if (b[bs] == '1') {
                    res += '0';
                    bs--;
                    continue;
                }
                res += '1';
                bs--;
                carry--;
                continue;
            }
            res += b[bs];
            bs--;
        }

        while (carry > 0) {
            res += '1';
            carry--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution test;
    string a = "1010", b = "1011";
    cout << test.addBinary(a, b);
    return 0;
}
