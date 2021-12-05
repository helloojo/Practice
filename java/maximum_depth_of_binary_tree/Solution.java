package maximum_depth_of_binary_tree;

class Solution {
	public int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		return findMaxDepth(root, 1);
	}

	private int findMaxDepth(TreeNode node, int depth) {
		if (node.left == null && node.right == null) {
			return depth;
		}
		int d = depth;
		if (node.left != null) {
			depth = Math.max(depth, findMaxDepth(node.left, d + 1));
		}
		if (node.right != null) {
			depth = Math.max(depth, findMaxDepth(node.right, d + 1));
		}
		return depth;
	}
}