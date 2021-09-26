package running_sum_of_1d_array;

class Solution {
    public int[] runningSum(int[] nums) {
        int[] answer = new int[nums.length];
        int numsLength = nums.length;
        answer[0] = nums[0];
        for (int i = 1; i < numsLength; i++) {
            answer[i] = answer[i - 1] + nums[i];
        }
        return answer;
    }
}
