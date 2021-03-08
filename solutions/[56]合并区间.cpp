#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> ans;
		if (intervals.empty())
			return ans;

		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(intervals.begin(), intervals.end());
		vector<int> cur = pq.top();
		pq.pop();
		while (!pq.empty()) {
			vector<int> next = pq.top();
			pq.pop();
			if (cur[1] >= next[0])
				cur[1] = (cur[1] < next[1] ? next[1] : cur[1]);
			else {
				ans.push_back(cur);
				cur = next;
			}
		}
		ans.push_back(cur);

		return ans;
	}
};