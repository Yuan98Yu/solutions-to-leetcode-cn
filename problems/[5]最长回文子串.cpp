#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	//��1��������ɢ��
	string longestPalindrome(string s) {
		if (s == "")
			return "";
		int left=0, right=-1;
		int len1, len2, tmp_max;
		for (int i = 0; i < s.size(); i++) {
			len1 = expand_around_center(s, i, i);
			len2 = expand_around_center(s, i, i + 1);
			tmp_max = max(len1, len2);
			if (tmp_max > right - left + 1) {
				left = i - (tmp_max - 1) / 2;
				right = i + tmp_max / 2;
			}
		}
		return s.substr(left, right - left + 1);
	}

private:
	//��1 ������ɢ��
	int expand_around_center(string &s, int left, int right) {
		for (; left >= 0 && right < s.size() && s[left] == s[right]; left--, right++)
			;
		return right - left - 1;
	}
};