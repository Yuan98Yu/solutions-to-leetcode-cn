#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty() || k == 0)
			return 0;
		if (k < prices.size() / 2) {
			vector<vector<int>> s(k, vector<int>(2, INT_MIN));
			s[0][0] = -prices[0];
			s[k - 1][1] = 0;

			for (int i = 1; i < prices.size(); ++i) {
				s[0][0] = max(s[0][0], -prices[i]);
				s[0][1] = max(s[0][1], s[0][0] + prices[i]);
				for (int j = 1; j < k; ++j) {
					s[j][0] = max(s[j][0], s[j - 1][1] - prices[i]);
					s[j][1] = max(s[j][1], s[j][0] + prices[i]);
				}
			}
			return s[k - 1][1];
		}
		else {
			int ans = 0;
			int price = prices[0];
			for (int i = 1; i < prices.size(); ++i) {
				if (prices[i] > price)
					ans += prices[i] - price;
				price = prices[i];
			}
			return ans;
		}
	}
};