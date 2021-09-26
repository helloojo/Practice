package add_to_array_form_of_integer;

import java.util.LinkedList;
import java.util.List;

class Solution {
	public List<Integer> addToArrayForm(int[] num, int k) {
		int length = num.length;
		List<Integer> answer = new LinkedList<>();
		for (int digit = 0; digit < length; digit++) {
			int curIdx = length - (digit + 1);
			int curNum = num[curIdx] + k % 10;
			k /= 10;
			if (curNum >= 10) {
				curNum %= 10;
				k += 1;
			}
			answer.add(0, curNum);
		}
		while (k > 0) {
			answer.add(0, k % 10);
			k /= 10;
		}
		return answer;
	}
}
