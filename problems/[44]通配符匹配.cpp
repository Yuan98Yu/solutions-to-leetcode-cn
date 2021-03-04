#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		bool** is_match;
		is_match = new bool * [s.size()+1];
		for (int i = 0; i <= s.size(); ++i)
			is_match[i] = new bool[p.size()+1];
		is_match[0][0] = true;
		for (int j = 1; j <= p.size(); ++j) {
			is_match[0][j] = is_match[0][j - 1] && p[j - 1] == '*';
		}
		for (int i = 1; i <= s.size(); ++i)
			is_match[i][0] = false;

		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= p.size(); j++) {
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
					is_match[i][j] = is_match[i - 1][j - 1];
				}
				else if (p[j - 1] == '*') {
					is_match[i][j] = is_match[i][j - 1] || is_match[i - 1][j];
				}
				else
					is_match[i][j] = false;
			}
		}

		return is_match[s.size()][p.size()];
	}
};