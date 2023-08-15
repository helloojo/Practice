package container_with_most_water;

class Solution {
    public int maxArea(int[] height) {
        int start = 0;
        int end = height.length - 1;
        int maxArea = 0;
        while (start < end) {
            final int width = end - start;
            if (height[end] >= height[start]) {
                maxArea = Math.max(maxArea, width * height[start]);
                start++;
            } else {
                maxArea = Math.max(maxArea, width * height[end]);
                end--;
            }
        }
        return maxArea;
    }
}
