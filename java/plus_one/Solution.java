package plus_one;

import java.util.LinkedList;
import java.util.List;

class Solution {
	public int[] plusOne(int[] digits) {
		int length = digits.length;
		List<Integer> answer = new LinkedList<>();
		int plus = 1;
		for (int i = length - 1; i >= 0; i--) {
			int curNum = digits[i] + plus;
			plus /= 10;
			if (curNum >= 10) {
				curNum %= 10;
				plus += 1;
			}
			answer.add(0, curNum);
		}
		if (plus > 0) {
			answer.add(0, plus);
		}
		return answer.stream().mapToInt(i -> i).toArray();
	}
}
