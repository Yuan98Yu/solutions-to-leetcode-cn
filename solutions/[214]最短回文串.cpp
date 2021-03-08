// 题目可理解为，寻找以s最左为左端的最长回文子串

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string shortestPalindrome(string s) {
		int right;
		string tmp_s("");
		for (right = s.size() - 1; right >= 0; right--) {
			bool flag = true;
			for (int tmp_left = 0, tmp_right = right; tmp_right > tmp_left; tmp_left++, tmp_right--) {
				if (s[tmp_right] != s[tmp_left]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (right < s.size() - 1) {
					tmp_s = s.substr(right + 1);
					reverse(tmp_s.begin(), tmp_s.end());
				}
				break;
			}
		}
		return tmp_s + s;
	}
};