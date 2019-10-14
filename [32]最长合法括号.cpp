#include <string>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string str) {
		if (str.empty())
			return 0;
		int mlen = 0;
		int slen = str.length();
		int* dp = new int[slen + 1];
		dp[0] = 0; dp[1] = 0;
		for (int i = 2; i < slen + 1; ++i) {
			if (str[i - 1] == '(')
				dp[i] = 0;
			else {
				int left_paren = i - 2 - dp[i - 1];
				if (left_paren >= 0 && str[left_paren] == '(') {
					dp[i] = 2 + dp[i - 1];
					// Æ´½ÓÓÐÐ§×Ö·û´®
					dp[i] += dp[i - dp[i]];

					if (dp[i] > mlen)
						mlen = dp[i];
				}
				else
					dp[i] = 0;
			}
		}
		return mlen;
	}
};