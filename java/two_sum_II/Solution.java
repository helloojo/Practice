package two_sum_II;

class Solution {
	public int[] twoSum(int[] numbers, int target) {
		int n = numbers.length;
		int i = 0, j = n - 1;
		int sum = numbers[i] + numbers[j];
		while (i < j) {
			if (sum == target) {
				return new int[]{i + 1, j + 1};
			}
			if (sum > target) {
				sum -= numbers[j--];
				sum += numbers[j];
			} else {
				sum -= numbers[i++];
				sum += numbers[i];
			}
		}
		return new int[]{0, 0};
	}
}