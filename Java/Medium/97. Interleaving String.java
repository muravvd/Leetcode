/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
*/

class Solution {    // 0ms 41mb, could get better space efficiency with dynamic programming
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        Boolean[][] memo = new Boolean[s1.length() + 1][s2.length() + 1];
        return check(s1, s2, s3, 0, 0, memo);
    }

    public boolean check(String s1, String s2, String s3, int pos1, int pos2, Boolean[][] memo) {
        if (pos1 + pos2 == s3.length())
            return true;
        if (memo[pos1][pos2] != null)
            return memo[pos1][pos2];
        if (pos1 < s1.length() && s1.charAt(pos1)==s3.charAt(pos1 + pos2))
            if (check(s1, s2, s3, pos1 + 1, pos2, memo))
                return memo[pos1][pos2] = true;  // присваивает memo[][] значение true и возвращает true
        if (pos2 < s2.length() && s2.charAt(pos2)==s3.charAt(pos1 + pos2))
            if (check(s1, s2, s3, pos1, pos2 + 1, memo))
                return memo[pos1][pos2] = true;
        return memo[pos1][pos2] = false;
    }

    public static class Main {
        public static void main(String[] args) {
            Solution solution = new Solution();
            String s1 = "aabcc";
            String s2 = "dbbca";
            String s3 = "aadbbcbcac";
            String s4 = "aadbbbaccc";
            System.out.println(solution.isInterleave(s1, s2, s3));
            System.out.println(solution.isInterleave(s1, s2, s4));
        }
    }
}