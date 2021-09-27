package replace_words;

import java.util.EnumMap;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

enum ALPHABET {
	a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

	public static Map<Character, ALPHABET> map;

	static {
		map = new HashMap<>();
		for (ALPHABET al : ALPHABET.values()) {
			map.put(al.name().charAt(0), al);
		}
	}

	public static ALPHABET convert(char c) {
		return map.get(c);
	}
}

class AlphabetNode {
	Map<ALPHABET, AlphabetNode> next = new EnumMap<>(ALPHABET.class);
	boolean end = false;

	public AlphabetNode get(ALPHABET a) {
		return next.get(a);
	}

	public AlphabetNode put(ALPHABET a) {
		return next.computeIfAbsent(a, alphabet -> new AlphabetNode());
	}
}

class Solution {
	AlphabetNode rootTrie;

	public String replaceWords(List<String> dictionary, String sentence) {
		generateTrie(dictionary);
		StringBuilder builder = new StringBuilder();
		int length = sentence.length();
		int i = 0;
		AlphabetNode cur;
		char c;
		while (i < length) {
			c = sentence.charAt(i);
			cur = rootTrie.get(ALPHABET.convert(c));
			while (cur != null) {
				builder.append(c);
				if (cur.end || ++i >= length) {
					break;
				}
				c = sentence.charAt(i);
				cur = cur.get(ALPHABET.convert(c));
			}
			while (i < length && sentence.charAt(i) != ' ') {
				if (cur == null || !cur.end) {
					builder.append(sentence.charAt(i));
				}
				i++;
			}
			if (i <= length - 1) {
				builder.append(sentence.charAt(i++));
			}
		}
		return builder.toString();
	}

	private void generateTrie(List<String> dictionary) {
		rootTrie = new AlphabetNode();
		AlphabetNode cur;
		for (String word : dictionary) {
			cur = rootTrie;
			for (char c : word.toCharArray()) {
				cur = cur.put(ALPHABET.convert(c));
			}
			cur.end = true;
		}
	}
}
