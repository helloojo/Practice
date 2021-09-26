package roman_to_integer;

import java.util.HashMap;
import java.util.Map;

class Solution {
    private final Map<Character, Integer> romanMap;

    public Solution() {
        romanMap = new HashMap<>();
        romanMap.put('I', 1);
        romanMap.put('V', 5);
        romanMap.put('X', 10);
        romanMap.put('L', 50);
        romanMap.put('C', 100);
        romanMap.put('D', 500);
        romanMap.put('M', 1000);
    }

    public int romanToInt(String s) {
        int size = s.length();
        int i = size - 1;
        int result = 0;
        while (i >= 0) {
            int num = romanMap.get(s.charAt(i));
            if (result >= num * 5) {
                result -= num;
            } else {
                result += num;
            }
            i--;
        }
        return result;
    }
}
