package longest_substring_without_repeating_characters;

import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int longestSubStrLength = 0;
        Set<Character> charSet=new HashSet<>();
        int start = 0;
        int end = 0;
        int strLength = s.length();
        while (end != strLength) {
            if (charSet.contains(s.charAt(end))) {
                longestSubStrLength = Math.max(longestSubStrLength, end - start);
                charSet.remove(s.charAt(start++));
            } else {
                if (end < strLength) {
                    charSet.add(s.charAt(end++));
                }
            }
        }
        longestSubStrLength = Math.max(longestSubStrLength, end - start);
        return longestSubStrLength;
    }
}
