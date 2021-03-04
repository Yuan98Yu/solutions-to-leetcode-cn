#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s) {
		string ans;

		int alphabet[26] = { 0 };
		bool is_have_c[26] = { 0 };
		vector<char> c_stack;
		for (char c : s) {
			++alphabet[c - 'a'];
		}
		for (char c : s) {
			--alphabet[c - 'a'];
			if (is_have_c[c - 'a']) {
				continue;
			}
			else {
				while (!c_stack.empty() && *c_stack.rbegin() > c && alphabet[*c_stack.rbegin() - 'a']) {
					is_have_c[*c_stack.rbegin() - 'a'] = false;
					c_stack.pop_back();
				}
				is_have_c[c - 'a'] = true;
				c_stack.push_back(c);
			}
		}
		for (char c : c_stack) {
			ans += c;
		}
		return ans;
	}
};