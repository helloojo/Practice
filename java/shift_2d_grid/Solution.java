package shift_2d_grid;

import java.util.ArrayList;
import java.util.List;

class Solution {
	public List<List<Integer>> shiftGrid(int[][] grid, int k) {
		int m = grid.length;
		int n = grid[0].length;
		List<List<Integer>> answer = new ArrayList<>(m);
		for (int i = 0; i < m; i++) {
			List<Integer> list = new ArrayList<>(n);
			for (int j = 0; j < n; j++) {
				list.add(null);
			}
			answer.add(list);
		}

		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				int nx = (x + (y + k) / n) % m;
				int ny = (y + k) % n;
				List<Integer> integers = answer.get(nx);
				integers.set(ny, grid[x][y]);
			}
		}
		return answer;
	}
}
