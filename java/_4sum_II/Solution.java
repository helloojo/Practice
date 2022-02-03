package _4sum_II;

import java.util.HashMap;
import java.util.Map;

public class Solution {
	public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
		int n = nums1.length;
		int totalCount = 0;
		int i, j;
		Map<Integer, Integer> m = new HashMap<>();
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				m.compute(-(nums1[i] + nums2[j]), (integer, integer2) -> integer2 == null ? 1 : integer2 + 1);
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				totalCount += m.getOrDefault(nums3[i] + nums4[j], 0);
			}
		}
		return totalCount;
	}
}
