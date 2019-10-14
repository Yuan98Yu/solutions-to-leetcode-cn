#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (intervals.empty()) {
			intervals.push_back(newInterval);
			return intervals;
		}
		int left = 0;
		int right = intervals.size();
		int target = newInterval[0];
		while (left < right) {
			int mid = (left + right) / 2;
			if (intervals[mid][0] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		
		int i;
		int sp;
		vector<int> cur;
		if (left == 0 || intervals[left-1][1] < newInterval[0]) {
			cur = newInterval;
			sp = left;
		}
		else {
			cur = intervals[left-1];
			cur[1] = max(cur[1], newInterval[1]);
			sp = left - 1;
		}
		for (i = left; i < intervals.size(); ++i) {
			if (cur[1] >= intervals[i][0])
				cur[1] = max(cur[1], intervals[i][1]);
			else
				break;
		}
		intervals.erase(intervals.begin() + sp, intervals.begin()+i);
		intervals.insert(intervals.begin() + sp, cur);
		return intervals;
	}
};