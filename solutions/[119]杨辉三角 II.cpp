#include <vector>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> ans(rowIndex + 1);
		ans[0] = 1;
		int t1 = rowIndex;
		for (int i = 1; i < ans.size(); ++i) {
			ans[i] = (long)ans[i - 1] * t1-- / i;
		}
		return ans;
	}
};

