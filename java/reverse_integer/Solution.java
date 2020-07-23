package reverse_integer;

public class Solution {
    public int reverse(int x) {
        long ret = 0;
        while (x != 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }
        if (ret > Integer.MAX_VALUE || ret < Integer.MIN_VALUE) {
            ret = 0;
        }
        return (int)ret;
    }
}