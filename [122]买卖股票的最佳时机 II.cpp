#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int ans = 0;
		int price = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > price)
				ans += prices[i] - price;

			price = prices[i];				
		}

		return ans;
	}
};