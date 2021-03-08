#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<string, int> m = { {"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000} };
		int r = m[s.substr(0, 1)];
		for (int i = 1; i < s.size(); ++i) {
			string two = s.substr(i - 1, 2);
			string one = s.substr(i, 1);
			r += m[two] ? m[two] : m[one];
		}
		return r;
	}
	int romanToInt2(string s) {
		int r = 0;

		unordered_map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

		int i = 0;
		for (; i < s.length() - 1; i++) {
			if (m[s[i]] < m[s[i + 1]])
				r -= m[s[i]];
			else
				r += m[s[i]];
		}
		r += m[s[i]];
		return r;
	}
};