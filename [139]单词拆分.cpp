#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	//动态规划，自底向上
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> memo(s.length() + 1, false);
		memo[0] = true;
		set<string> ws(wordDict.begin(), wordDict.end());

		for (int i = 1; i <= s.length(); ++i) {
			for (int j = 0; j < i; ++j) {
				if (memo[j] && ws.find(s.substr(j, i - j)) != ws.end()) {
					memo[i] = true;
					break;
				}
			}
		}
		return memo[s.length()];
	}

	//递归写法
};