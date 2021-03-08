#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string result("");
		int round_num = 2 * numRows - 2;
		for (int j = 0; j < s.size(); j += round_num)
			result.push_back(s[j]);
		for (int i = 1; i < numRows - 1; i++) {
			int j;
			for (j = i; j + round_num - i - i < s.size(); j += round_num) {
				result.push_back(s[j]);
				result.push_back(s[j + round_num - i - i]);
			}
			if (j < s.size())
				result.push_back(s[j]);
		}
		for (int j = numRows - 1; j < s.size(); j += round_num)
			result.push_back(s[j]);

		return result;
	}
};