/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/


class Solution {    // 2ms 45mb
    public int addDigits(int num) {
        if (num < 10)
            return num;
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum >= 10)
            return addDigits(sum);
        return sum;
    }

    public static class Main {
        public static void main(String[] args) {
            Solution test = new Solution();
            int x = 38;
            System.out.println(test.addDigits(x));
        }
    }
}