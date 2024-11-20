/*
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'
"2" -> 'B'
...
"25" -> 'Y'
"26" -> 'Z'

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)

Given a string s containing only digits, return the number of ways to decode it.
If the entire string cannot be decoded in any valid way, return 0.
*/
import java.util.HashMap;
import java.util.Map;

class Solution {    // 2ms 45mb
    public int numDecodings(String s) {
        Map<Integer, Integer> memo = new HashMap<>(); // Memoization map
        return decode(s, 0, memo);
    }

    private int decode(String s, int i, Map<Integer, Integer> memo) {
        if (i == s.length())
            return 1; // end
        if (s.charAt(i) == '0')
            return 0; // leading zero
        if (memo.containsKey(i))
            return memo.get(i);
        int count = decode(s, i + 1, memo); // Single digit
        if (i + 1 < s.length()) {   // Double digit
            int twoDigit = Integer.parseInt(s.substring(i, i + 2));
            if (twoDigit >= 10 && twoDigit <= 26)
                count += decode(s, i + 2, memo);
        }
        memo.put(i, count);
        return count;
    }

    public static class Main {
        public static void main(String[] args) {
            String s = "06";
            Solution test = new Solution();
            int result = test.numDecodings(s);
            System.out.println(result);
        }
    }
}