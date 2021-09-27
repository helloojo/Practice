package remove_duplicates_from_sorted_array;

class Solution {
	public int removeDuplicates(int[] nums) {
		int sortIdx = 0;
		int length = nums.length;
		int prevNum = 101;
		for (int i = 0; i < length; i++) {
			if (prevNum != nums[i]) {
				nums[sortIdx++] = nums[i];
				prevNum = nums[i];
			}
		}
		return sortIdx;
	}
}
