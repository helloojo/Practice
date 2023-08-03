package restore_ip_addresses;

import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;

class Solution {
    private final List<String> answer = new ArrayList<>();

    public List<String> restoreIpAddresses(String s) {
        if (s.length() > 12) {
            return List.of();
        }
        parseString(s.toCharArray(), new StringJoiner("."), 0, 0);
        return answer;
    }

    private void parseString(char[] s, StringJoiner cur, int idx, int depth) {
        if (depth > 4 || (s.length - idx - 1) / 3 > 4 - depth) {
            return;
        }
        if (idx >= s.length && depth == 4) {
            answer.add(cur.toString());
            return;
        }
        if (idx >= s.length) {
            return;
        }
        int num = 0;
        while (0 <= num && num <= 255 && idx < s.length) {
            num *= 10;
            num += s[idx] - '0';
            if (0 <= num && num <= 255) {
                final var joiner = new StringJoiner(".");
                joiner.merge(cur);
                parseString(s, joiner.add(String.valueOf(num)), idx + 1, depth + 1);
            }
            if (num == 0) {
                break;
            }
            idx++;
        }
    }
}
