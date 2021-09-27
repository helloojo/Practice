package implement_trie;

class Trie {
	private static final int NODE_ARR_SIZE = 26;

	private static class Node {
		private boolean end = false;
		private final Node[] next = new Node[NODE_ARR_SIZE];

		public Node get(char c) {
			return next[c - 'a'];
		}

		public Node put(char c) {
			int i = c - 'a';
			if (next[i] == null) {
				next[i] = new Node();
			}
			return next[i];
		}

		public void setEnd() {
			this.end = true;
		}
	}

	private final Node root;
	private Node cur;

	public Trie() {
		root = new Node();
	}

	public void insert(String word) {
		cur = root;
		for (char c : word.toCharArray()) {
			cur = cur.put(c);
		}
		cur.setEnd();
	}

	public boolean search(String word) {
		find(word);
		return cur != null && cur.end;
	}

	public boolean startsWith(String prefix) {
		find(prefix);
		return cur != null;
	}

	private void find(String word) {
		cur = root;
		for (char c : word.toCharArray()) {
			cur = cur.get(c);
			if (cur == null) {
				break;
			}
		}
	}
}
