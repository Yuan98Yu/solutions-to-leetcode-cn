#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		vector<string> cur;
		dp(s, cur, ans, 3);
		return ans;
	}
private:
	void dp(string s, vector<string>& cur, vector<string>& ans, int dots) {
		if (dots == 0) {
			if (is_valid(s)) {
				string tmp = *cur.begin();
				for (vector<string>::iterator p = cur.begin() + 1; p != cur.end(); ++p)
					tmp += '.' + *p;
				tmp += '.' + s;
				ans.push_back(tmp);
			}
			return;
		}


		for (int i = 1; i <= 3 && i <= s.length(); ++i) {
			if (!is_valid(s.substr(0, i)))
				continue;
			cur.push_back(s.substr(0, i));
			dp(s.substr(i), cur, ans, dots - 1);
			cur.pop_back();
		}
	}

	bool is_valid(string s) {
		if (s.length() > 3 || s.empty())
			return false;
		return s[0] == '0' ? s.length() == 1 : stoi(s) <= 255;
	}
};