import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

class Solution {
    public void backtrack(int i, int[] nums, List<Integer> cur, List<List<Integer>> res) {
        res.add(new ArrayList<>(cur));
        for (int j = i; j < nums.length; j++) {
            if (j > i && nums[j] == nums[j - 1])    // Skip duplicate elements
                continue;
            cur.add(nums[j]);
            backtrack(j + 1, nums, cur, res);
            cur.remove(cur.size() - 1);
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {     // 1ms 43mb
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums); // Sort the array to handle duplicates
        backtrack(0, nums, new ArrayList<>(), res);
        return res;
    }

    public static class Main {
        public static void printV(List<List<Integer>> vec) {
            System.out.print("| ");
            for (List<Integer> row : vec) {
                for (int val : row)
                    System.out.print(val + " ");
                System.out.print("| ");
            }
        }

        public static void main(String[] args) {
            int[] arr = {1, 2, 2};
            Solution test = new Solution();
            List<List<Integer>> result = test.subsetsWithDup(arr);
            printV(result);
        }
    }
}