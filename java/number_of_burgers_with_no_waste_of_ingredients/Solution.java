package number_of_burgers_with_no_waste_of_ingredients;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
	public List<Integer> numOfBurgers(int tomatoSlices, int cheeseSlices) {
		if (!canSolveProblem(tomatoSlices, cheeseSlices)) {
			return Collections.emptyList();
		}
		return Arrays.asList((tomatoSlices - 2 * cheeseSlices) / 2, (4 * cheeseSlices - tomatoSlices) / 2);
	}

	private boolean canSolveProblem(int t, int c) {
		return (t - 2 * c) > 0 && (4 * c - t) > 0 && (t - 2 * c) % 2 == 0 && (4 * c - t) % 2 == 0;
	}
}
