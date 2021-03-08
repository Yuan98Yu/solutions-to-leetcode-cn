#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		if (s.empty())
			return vector<vector<string>>();

		vector<vector<string>> ans;
		vector<string> path; 
		_dfs(s, path, ans);

		return ans;
	}

	void _dfs(string& s, vector<string>& path, vector<vector<string>>& ans) {
		if (s.empty()) {
			ans.push_back(path);
			return;
		}

		for (int len = 1; len <= s.length(); ++len) {
			string slice = s.substr(0, len);
			if (_isPalindrome(slice)) {
				path.push_back(slice);
				string str_remain = s.substr(len - 1, s.length() - len);
				_dfs(str_remain, path, ans);
				path.pop_back();
			}
		}
	}

	bool _isPalindrome(string& s) {
		int l = 0;
		int r = s.length() - 1;
		while (l < r && s[l] == s[r]) {
			l++;
			r--;
		}
		return l >= r;
	}
};