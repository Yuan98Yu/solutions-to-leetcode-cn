#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int result = 0;

		const int MAX = pow(2, 31) - 1;
		const int MIN = -pow(2, 31);

		bool is_negetive = false;
		string::iterator it = str.begin();
		for (; (*it == ' ' or *it == '/t' or *it == '/n') and it < str.end(); it++);
		if (*it == '-') {
			is_negetive = true;
			it++;
		}
		else if (*it == '+')
			it++;
		if (is_negetive) {
			for (; *it >= '0' and *it <= '9' and it < str.end(); it++) {
				if ((MIN  + *it - '0')/10 -result > 0) {
					result = MIN;
					break;
				}
				result = result*10 + '0' - *it ;
			}
		}
		else {
			for (; *it >= '0' and *it <= '9' and it < str.end(); it++) {
				if ((MAX  - *it + '0')/10 - result < 0 ) {
					result = MAX;
					break;
				}
					result = result *10 - '0' + *it;
			}
		}
		return result;
	}
};