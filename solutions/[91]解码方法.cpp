#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty())
			return 0;
		int pp = 1;
		int p = (s[0] == '0' ? 0 : 1);
		for (int i = 1; i < s.length(); ++i) {
			int tmp = 0;
			if (s[i] != '0')
				tmp += p;
			if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
				tmp += pp;
			pp = p;
			p = tmp;
		}
		return p;
	}
};