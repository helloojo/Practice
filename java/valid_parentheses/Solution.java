package valid_parentheses;

class Solution {
	public boolean isValid(String s) {
		char[] stack = new char[s.length()];
		int size = 0;
		boolean result = true;
		for (char c : s.toCharArray()) {
			if (c == '(' || c == '{' || c == '[') {
				stack[size++] = c;
			} else if (c == ')') {
				if (size == 0 || stack[size - 1] != '(') {
					result = false;
					break;
				}
				size--;
			} else if (c == '}') {
				if (size == 0 || stack[size - 1] != '{') {
					result = false;
					break;
				}
				size--;
			} else if (c == ']') {
				if (size == 0 || stack[size - 1] != '[') {
					result = false;
					break;
				}
				size--;
			} else {
				throw new AssertionError();
			}
		}
		return result && size == 0;
	}
}
