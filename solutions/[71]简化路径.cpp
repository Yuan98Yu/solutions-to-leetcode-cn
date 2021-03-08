#include <string>
#include <queue>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		deque<string> s;
		string tmp;
		string ans;
		for (char c : path) {
			if (c == '/') {
				if (tmp == "." || tmp.empty());
				else if (tmp == "..") {
					if (!s.empty())
						s.pop_back();
				}
				else
					s.push_back(tmp);
				tmp.clear();
			}
			else {
				tmp += c;
			}
		}
		if (!tmp.empty()) {
			if (tmp == "..") {
				if (!s.empty())
					s.pop_back();
			}
			else if (tmp != ".")
				s.push_back(tmp);
		}
		if (s.empty())
			ans = "/";
		for (string t : s) {
			ans += '/' + t;
		}
		return ans;
	}
};