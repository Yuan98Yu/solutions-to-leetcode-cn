#include <vector>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		if (ratings.empty())
			return 0;

		int ans;
		int* candies = new int[ratings.size()];
		candies[0] = 1;
		for (int i = 1; i < ratings.size(); ++i) {
			if (ratings[i] > ratings[i - 1])
				candies[i] = candies[i - 1] + 1;
			else
				candies[i] = 1;
		}
		ans = candies[ratings.size() - 1];
		for (int i = ratings.size() - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1] && candies[i + 1] + 1 > candies[i])
				candies[i] = candies[i + 1] + 1;
			ans += candies[i];
		}
		return ans;
	}
	
	//int candy2(vector<int>& ratings) {
	//	if (ratings.empty())
	//		return 0;

	//	int ans=0;
	//	int up=0;
	//	int down=0;
	//	for (int i = 1; i < ratings.size(); ++i) {
	//		if (ratings[i] > ratings[i - 1] && down == 0) {
	//			++up;
	//		}
	//		else if (ratings[i] < ratings[i - 1] && up == 0) {
	//			++down;
	//		}
	//		else
	//			candies[i] = 1;
	//		//pass
	//	}
	//	
	//	return ans;
	//}
};