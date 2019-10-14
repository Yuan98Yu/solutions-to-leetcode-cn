#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		s = del_space(s);
		if (s.empty())
			return false;

		if ( (is_sym(s[0]) && s.length() == 1 ) || (!is_sym(s[0]) && !is_num(s[0]) ) )
			return false;

		int flag = 0;
		for (int i = 1; i < s.length(); ++i) {
			if (is_num(s[i]))
				continue;
			else if (s[i] == 'e');
		}
	}
private:
	string del_space(string& s) {
		int i = 0;
		int j = s.length() - 1;
		for (; i <= j && s[i] == ' ' || s[i] == '\t' || s[i] == '\n'; ++i);
		for (; j >= i && s[j] == ' ' || s[j] == '\t' || s[j] == '\n'; --j);
		if (j < i)
			return "";

		return s.substr(i, j - i + 1);
	}
	bool is_num(char c) {
		return c >= '0' && c <= '9';
	}
	bool is_sym(char c) {
		return c == '-' || c == '+';
	}
	bool is_int(string& s) {

	}
};