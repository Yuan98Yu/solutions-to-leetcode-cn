#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	//法1:拆分为[0,i] [i,n) 各交易一次
	int maxProfit(vector<int>& prices) {
		int ans = 0;
		if (prices.empty())
			return ans;

		vector<int> left_max(prices.size());
		int right_max = 0;

		int min = prices[0];
		left_max[0] = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] < min) {
				min = prices[i];
				left_max[i] = left_max[i - 1];
			}
			left_max[i] = (left_max[i - 1] > prices[i] - min ? left_max[i - 1] : prices[i] - min);
		}
		int max = prices[prices.size() - 1];
		right_max = 0;
		for (int i = prices.size() - 2; i >= 0; --i) {
			if (prices[i] > max) {
				max = prices[i];
				//right_max不变
			}
			right_max = (right_max > max - prices[i] ? right_max : max - prices[i]);
			if (left_max[i] + right_max > ans)
				ans = left_max[i] + right_max;
		}
		return ans;
	}
	//法2：动态规划，第二维为交易次数

	//法3：有限状态机
	int maxProfit2(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = 0;
		for (int i = 1; i < prices.size(); ++i) {
			s1 = max(s1, -prices[i]);
			s2 = max(s2, s1 + prices[i]);
			s3 = max(s3, s2 - prices[i]);
			s4 = max(s4, s3 + prices[i]);
		}
		return s4;
	}
};