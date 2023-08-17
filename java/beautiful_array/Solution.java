package beautiful_array;

class Solution {
    public int[] beautifulArray(int n) {
        final int[] array = new int[n];
        if (n == 1) {
            array[0] = 1;
            return array;
        }
        final int[] left = beautifulArray((n + 1) / 2);
        int idx = 0;
        for (int num : left) {
            array[idx++] = num * 2 - 1;
        }
        final int[] right = beautifulArray(n / 2);
        for (int num : right) {
            array[idx++] = num * 2;
        }
        return array;
    }
}
