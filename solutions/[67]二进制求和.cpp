#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int i = 0;
		int max_len = (a.length() > b.length() ? a.length() : b.length());
		string ans;
		int carry = 0;
		for(int i=0;i<max_len;++i){
			int tmp = carry;
			if (i < a.length())
				tmp += a[a.length()-1-i] - '0';
			if (i < b.length())
				tmp += b[b.length() - 1 - i] - '0';
			if (tmp >= 2) {
				carry = 1;
				tmp -= 2;
			}
			else
				carry = 0;
			ans.insert(ans.begin(), tmp + '0');
		}
		if (carry)
			ans.insert(ans.begin(), '1');
		return ans;
	}
};