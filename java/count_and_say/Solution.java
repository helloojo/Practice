package count_and_say;

class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        String sayResult = countAndSay(n - 1);
        int resultLength = sayResult.length();
        StringBuilder stringBuilder = new StringBuilder();
        int prev = sayResult.charAt(0) - '0';
        int cnt = 1;
        for (int i = 1; i < resultLength; i++) {
            int code = sayResult.charAt(i) - '0';
            if (prev != code) {
                stringBuilder.append(cnt).append(prev);
                prev = code;
                cnt = 0;
            }
            cnt++;
        }
        if (cnt != 0) {
            stringBuilder.append(cnt).append(prev);
        }

        return stringBuilder.toString();
    }
}
