#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int idx = -1;

		vector<int> values = gas;
		for (int i = 0; i < values.size(); ++i) {
			values[i] -= cost[i];
		}

		int cum = 0;
		for (int i = 0; i < values.size(); ++i) {
			if (cum <= 0) {
				if (values[i] >= 0) {
					idx = i;
					cum = values[i];
				}
				else
					continue;
			}
			else
				cum += values[i];
		}

		if (cum < 0 || idx == -1)
			return -1;
		else {
			int cum2 = 0;
			for (int i = 0; i < idx; ++i)
				cum2 += values[i];
			if (cum2 + cum >= 0)
				return idx;
			else
				return -1;
		}
	}
};