/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below.
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {    // 1ms 44mb
    public int minimumTotal(List<List<Integer>> triangle) {
        int rows = triangle.size();
        if (rows == 1)
            return triangle.getFirst().getFirst();
        int[][] memo = new int[rows][rows];
        for (int[] row : memo)
            Arrays.fill(row, -1);
        return path(triangle, 0, 0, memo);
    }

    public int path(List<List<Integer>> triangle, int row, int i, int[][] memo) {
        if (row == triangle.size())
            return 0;
        if (memo[row][i] != -1)
            return memo[row][i];
        memo[row][i] = triangle.get(row).get(i) + Math.min(path(triangle, row + 1, i, memo), path(triangle, row + 1, i + 1, memo));

        return memo[row][i];
    }

    public static class Main {
        public static void main(String[] args) {
            Solution solution = new Solution();
            List<List<Integer>> triangle = new ArrayList<>();
            triangle.add(Arrays.asList(2));
            triangle.add(Arrays.asList(3, 4));
            triangle.add(Arrays.asList(6, 5, 7));
            triangle.add(Arrays.asList(4, 1, 8, 3));
            System.out.println(solution.minimumTotal(triangle));
        }
    }
}