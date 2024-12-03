/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

class Solution {    // 3ms 45mb
    public void moveZeroes(int[] nums) {
        int L = 0, n = nums.length;
        while (L < n && nums[L] != 0)
            L++;
        int R = L + 1;
        while (R < n && nums[R] == 0)
            R++;
        while (L < n && R < n) {
            if (nums[L] == 0 && nums[R] != 0) {
                int temp = nums[R];
                nums[R] = 0;
                nums[L] = temp;
                L++;
                R++;
                continue;
            }
            if (nums[L] != 0) {
                L++;
                continue;
            }
            if (nums[R] == 0)
                R++;
        }
        printArray(nums);
    }

    public void printArray(int[] nums) {
        for (int i = 0; i < nums.length; i++)
            System.out.print(nums[i] + " ");
    }

    public static class Main {
        public static void main(String[] args) {
            Solution solution = new Solution();
            int[] nums = new int[]{4,2,4,0,0,3,0,5,1,0};
            solution.moveZeroes(nums);
        }
    }
}