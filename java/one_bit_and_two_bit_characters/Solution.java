package one_bit_and_two_bit_characters;

class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        boolean isTwoBit = false;
        final int length = bits.length;
        for (int i = 0; i < length - 1; i++) {
            if (bits[i] == 1) {
                if (isTwoBit) {
                    isTwoBit = false;
                } else {
                    isTwoBit = true;
                }
            } else {
                if (isTwoBit) {
                    isTwoBit = false;
                }
            }
        }
        return !isTwoBit;
    }
}