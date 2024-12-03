/*
An ugly number is a positive integer which does not have a prime factor other than 2, 3, and 5.

Given an integer n, return true if n is an ugly number.
*/

class Solution {    // 0ms 41mb
    public boolean isUgly(int n) {
        if (n==0)
            return false;
        if (n==1)
            return true;
        if (n % 2 == 0)
            return isUgly(n / 2);
        if (n % 3 == 0)
            return isUgly(n / 3);
        if (n % 5 == 0)
            return isUgly(n / 5);
        return false;
    }

    public static class Main {
        public static void main(String[] args) {
            Solution solution = new Solution();
            System.out.println(solution.isUgly(14));
        }
    }
}