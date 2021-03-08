#include <vector>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int ans=0;
		int min=prices[0];
		int tmp;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] <= min)
				min = prices[i];
			else {
				tmp = prices[i] - min;
				if (tmp > ans)
					ans = tmp;
			}
		}
		return ans;
	}
};