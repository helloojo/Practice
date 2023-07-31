package integer_to_roman;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;

class Solution {
    public String intToRoman(int num) {
        final StringBuilder builder = new StringBuilder();
        final Map<Integer, String> romanMap = new LinkedHashMap<>();
        romanMap.put(1000, "M");
        romanMap.put(900, "CM");
        romanMap.put(500, "D");
        romanMap.put(400, "CD");
        romanMap.put(100, "C");
        romanMap.put(90, "XC");
        romanMap.put(50, "L");
        romanMap.put(40, "XL");
        romanMap.put(10, "X");
        romanMap.put(9, "IX");
        romanMap.put(5, "V");
        romanMap.put(4, "IV");
        romanMap.put(1, "I");

        for (Entry<Integer, String> entry : romanMap.entrySet()) {
            if (num == 0) {
                break;
            }
            final int unit = entry.getKey();
            final String roman = entry.getValue();
            final int repeat = num / unit;
            if (repeat != 0) {
                builder.append(roman.repeat(repeat));
                num %= unit;
            }
        }

        return builder.toString();
    }
}