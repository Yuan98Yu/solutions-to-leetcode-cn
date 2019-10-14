#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/*
		法1：记录当前的左括号和右括号的数量。
			当前左括号数量大于等于右括号数量时，合法；
			否则，非法。
		以下为递归程序。
	*/
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if (n == 0)
			return ans;
		dp(ans, n - 1, n, "(");
		return ans;
	}

	void dp(vector<string>& ans, int l_remain, int r_remain, string str) {
		if (l_remain == 0 && r_remain == 0) {
			ans.push_back(str);
			return;
		}

		if (l_remain > 0)
			dp(ans, l_remain - 1, r_remain, str + '(');
		if (l_remain < r_remain)
			dp(ans, l_remain, r_remain - 1, str + ')');
	}
	/*
	法2：将每个生成的序列分为left、right两部分，且left、right为合法的（假设空字符串合法）。
		要增加括号，可找出每一对合法的left、right，并在每个left的两边加左右括号。
	可写为递归程序（需动态规划）。
	*/
};