package time_needed_to_inform_all_employees;

class Solution {
	private int[] cumulativeInformTime;

	public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
		cumulativeInformTime = new int[n];
		int totalInformTime = 0;
		for (int i = 0; i < n; i++) {
			if (informTime[i] != 0) {
				continue;
			}
			totalInformTime = Math.max(totalInformTime, calculateTree(i, manager, informTime));
		}
		return totalInformTime;
	}

	private int calculateTree(int pos, int[] manager, int[] informTime) {
		if (pos == -1) {
			return 0;
		}
		if (cumulativeInformTime[pos] != 0) {
			return cumulativeInformTime[pos];
		}
		return cumulativeInformTime[pos] = calculateTree(manager[pos], manager, informTime) + informTime[pos];
	}
}
