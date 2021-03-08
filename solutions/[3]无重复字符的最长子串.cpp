/**
*	使用集合或map来确定有无重复字符，使用map的好处是能够建立字符和字符出现的位置的映射
*	假设字符有256个，那么使用一个size为256的数组作为map即可，否则可使用hashmap
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int map[256] = { 0 };
		int left = 1;
		int max_len = 0;
		if (s.size() > 0)
			max_len = 1;
		for (int i = 0; i < s.size(); i++) {
			if (map[s[i]] >= left) {
				if (i - left + 1 > max_len)
					max_len = i - left + 1;
				left = map[s[i]] + 1;
			}
			map[s[i]] = i + 1;
		}
		if (s.size() - left + 1 > max_len)
			max_len = s.size() - left + 1;
		return max_len;
	}
};
