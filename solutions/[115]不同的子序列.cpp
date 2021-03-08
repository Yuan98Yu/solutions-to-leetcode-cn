#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) {
		int s_len = s.length();
		int t_len = t.length();
		vector<vector<long long>> dp(s_len + 1, vector<long long>(t_len + 1));
		for (int i = 0; i <= s_len; ++i)
			dp[i][0] = 1;
		for (int j = 1; j <= t_len; ++j)
			dp[0][j] = 0;
		for (int i = 1; i <= s_len; ++i) {
			for (int j = 1; j <= t_len; ++j) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[s_len][t_len];
	}
};