/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

1 <= n <= 45
*/

#include <iostream>
using namespace std;

/*
class Solution {       // 3ms
    // Fibonacci sequence
public:
    int climbStairs(int n) {
        if (n < 2)
            return n;
        vector<int> steps(n+1);
        steps[0] = 1;
        steps[1] = 1;
        for (int i = 2; i <= n; i++)
            steps[i] = steps[i - 1] + steps[i - 2];
        return steps[n];
    }
};
*/

class Solution {        // 0ms - 2ms
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int first = 1;
        int second = 1;
        int current;
        for (int i = 2; i <= n; i++) {
            current = first + second;
            first = second;
            second = current;
        }
        return current;
    }
};

int main() {
    Solution test;
    int a = 5;   // 8
    cout << test.climbStairs(a);
    return 0;
}