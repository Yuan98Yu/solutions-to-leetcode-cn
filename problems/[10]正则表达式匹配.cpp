#include <string>
#include <vector>
using namespace std;
/*
	若pattern不存在'*'，则直接顺序匹配即可
	由于存在'*', 可匹配的个数不定，自然的想法是使用回溯法；由于存在重叠子问题，引申的做法是动态规划。
	动态规划的写法可分两种：自顶向下，自底向上
*/
class Solution {
public:
	/*
		递归，回溯
	*/
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		//if (s.empty()) {
		//	return p.length() >= 2 and p[1] == '*' and isMatch(s, p.substr(2));
		//}

		bool first_match = !s.empty() && ((s[0] == p[0]) || p[0] == '.');
		if (p.length() >= 2 and p[1] == '*') {
			return isMatch(s, p.substr(2))
				or (first_match and isMatch(s.substr(1), p));
		}
		else {
			return first_match and isMatch(s.substr(1), p.substr(1));
		}
	}
	/*
		自底向上，动态规划
	*/
	bool isMatch2(string str, string pattern) {
		size_t len1 = str.size();
		size_t len2 = pattern.size();
		if (len2 && pattern[0] == '*')
			return false;
		vector<vector<bool>>flag(len1 + 1, vector<bool>(len2 + 1, false));
		flag[0][0] = true;
		for (size_t i = 1; i <= len2; ++i) {
			if (pattern[i - 1] == '*')
				flag[0][i] = flag[0][i - 1] || flag[0][i - 2];
		}
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if ((pattern[j - 1] == str[i - 1]) || (pattern[j - 1] == '.'))
					flag[i][j] = flag[i - 1][j - 1];
				else if (pattern[j - 1] == '*') {
					if ((str[i - 1] == pattern[j - 2]) || (pattern[j - 2] == '.')) {
						flag[i][j] = (flag[i][j - 2] || flag[i][j - 1] || flag[i - 1][j]);
					}
					else {
						flag[i][j] = flag[i][j - 2];
					}
				}
				else {
					flag[i][j] = false;
				}
			}
		}
		return flag[len1][len2];
	}
	/*
		递归，动态规划
	*/
	bool isMatch3(string s, string p) {
		struct Rec_fun {
			bool dp(int i, int j) {
				
			}
		};
		Rec_fun fun;
		return fun.dp(0, 0);
	}
};