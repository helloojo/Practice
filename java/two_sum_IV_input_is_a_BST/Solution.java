package two_sum_IV_input_is_a_BST;

class Solution {
	public boolean findTarget(TreeNode root, int k) {
		return traversal(root, root, k);
	}

	private boolean traversal(TreeNode root, TreeNode here, int k) {
		boolean result = false;
		if (here.left != null) {
			result = traversal(root, here.left, k);
		}
		if (here.right != null) {
			result |= traversal(root, here.right, k);
		}
		return result || findLessTarget(root, here, k - here.val);
	}

	private boolean findLessTarget(TreeNode here, TreeNode base, int remain) {
		if (here == null) {
			return false;
		}
		if (here != base && here.val == remain) {
			return true;
		}
		if (here.val < remain) {
			return findLessTarget(here.right, base, remain);
		} else {
			return findLessTarget(here.left, base, remain);
		}
	}
}
