package integer_to_english_words;

import java.util.Map;
import java.util.StringJoiner;

class Solution {
    private static final int[] overHundred = { 1_000_000_000, 1_000_000, 1_000 };
    private static final String[] overHundredStr = { "Billion", "Million", "Thousand" };
    private static final String[] underTwenty = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
            "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
    };
    private static final Map<Integer, String> betweenTwentyToHundred = Map.of(
            20, "Twenty",
            30, "Thirty",
            40, "Forty",
            50, "Fifty",
            60, "Sixty",
            70, "Seventy",
            80, "Eighty",
            90, "Ninety"
    );

    public String numberToWords(int num) {
        if (num == 0) {
            return underTwenty[0];
        }
        final StringJoiner joiner = new StringJoiner(" ");
        int overHundredIdx = 0;

        while (num > 0) {
            if (overHundredIdx < overHundred.length) {
                final int repeat = num / overHundred[overHundredIdx];
                if (repeat > 0) {
                    joiner.merge(generateUnderThousand(repeat));
                    joiner.add(overHundredStr[overHundredIdx]);
                    num %= overHundred[overHundredIdx];
                }
                overHundredIdx++;
            } else {
                joiner.merge(generateUnderThousand(num));
                num = 0;
            }
        }
        return joiner.toString();
    }

    private static StringJoiner generateUnderThousand(int underThousandNum) {
        final StringJoiner joiner = new StringJoiner(" ");
        while (underThousandNum > 0) {
            if (underThousandNum < 20) {
                joiner.add(underTwenty[underThousandNum]);
                underThousandNum = 0;
            }
            if (underThousandNum >= 100) {
                final int quotient = underThousandNum / 100;
                joiner.add(underTwenty[quotient]);
                joiner.add("Hundred");
                underThousandNum %= 100;
            } else if (underThousandNum > 0) {
                final int remainder = underThousandNum % 10;
                final int removeRemainder = underThousandNum - remainder;
                joiner.add(betweenTwentyToHundred.get(removeRemainder));
                if (remainder != 0) {
                    joiner.add(underTwenty[remainder]);
                }
                underThousandNum = 0;
            }
        }
        return joiner;
    }
}
