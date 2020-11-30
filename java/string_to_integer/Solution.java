package string_to_integer;

public class Solution {
    public int myAtoi(String str) {
        long result = 0;
        str = str.trim();
        int strLength = str.length();
        int sign = 1;
        for (int i = 0; i < strLength; i++) {
            char c = str.charAt(i);
            if (isDigit(c)) {
                result = result * 10 + (c - '0');
            } else if (isSign(c) && i == 0) {
                sign = c == '+' ? 1 : -1;
            } else {
                break;
            }
            if (result * sign < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            } else if (result * sign > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
        }
        result *= sign;
        return (int)result;
    }

    boolean isDigit(char digit) {
        return digit >= '0' && digit <= '9';
    }

    boolean isSign(char sign) {
        return sign == '+' || sign == '-';
    }
}
