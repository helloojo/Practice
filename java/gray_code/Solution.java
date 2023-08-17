package gray_code;

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> grayCode(int n) {
        final int size = 1 << n;
        final List<Integer> answer = new ArrayList<>(size);
        for (int binary = 0; binary < size; binary++) {
            answer.add(binary ^ (binary >> 1));
        }
        return answer;
    }
}
