#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		int i = s.length()-1;
		for (; i >= 0 && s[i] == ' '; --i);
		for (; i >= 0 && s[i] != ' '; --i, ++count);

		return count;
	}
};