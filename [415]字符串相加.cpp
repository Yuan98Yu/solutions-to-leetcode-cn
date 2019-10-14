#include <string>
using namespace std;

class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans;

		int p1 = num1.length() - 1;
		int p2 = num2.length() - 1;
		int carry = 0;
		char tmp;
		for (; p1 >= 0 || p2 >= 0; p1--, p2--) {
			tmp = carry + '0';
			if (p1 >= 0)
				tmp += num1[p1] - '0';
			if (p2 >= 0)
				tmp += num2[p2] - '0';
			if (tmp > '9') {
				tmp -= 10;
				carry = 1;
			}
			else
				carry = 0;
			ans.insert(ans.begin(), tmp);
		}

		if (carry == 1)
			ans.insert(ans.begin(), '1');

		return ans;
	}
};