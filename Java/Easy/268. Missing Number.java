/*
Given an array nums containing n distinct numbers in the range [0, n],
return the only number in the range that is missing from the array.
*/

class Solution {    // 0ms 45mb
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int allsum = n*(n+1)/2;
        for (int num : nums)
            allsum -= num;
        return allsum;
    }

    public static class Main {
        public static void main(String[] args) {
            Solution solution = new Solution();
            int[] nums = new int[]{9,6,4,2,3,5,7,0,1};
            System.out.println(solution.missingNumber(nums));
        }
    }
}