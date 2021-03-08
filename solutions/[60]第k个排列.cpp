#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string ans;
		vector<int> nums(n);
		vector<int> factorials = getMul(n - 1);
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] = i + 1;
		}
		for (; n > 0; --n) {
			int p = (k - 1) / factorials[n - 1];
			k = k - p * factorials[n - 1];
			ans += '0' + nums[p];
			nums.erase(nums.begin() + p);
		}
		return ans;
	}
	vector<int> getMul(int n) {
		vector<int> res = { 1 };
		for (int i = 1; i <= n; i++) {
			res.push_back(res[i - 1] * i);
		}
		return res;
	}
};