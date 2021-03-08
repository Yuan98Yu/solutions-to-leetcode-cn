#include <vector>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> ans = { 0 };
		int head = 1;
		for (int i = 1; i <= n; ++i) {
			for (int i = ans.size() - 1; i >= 0; --i) {
				ans.push_back(ans[i]+head);
			}
			head <<= 1;
		}
		return ans;
	}
};