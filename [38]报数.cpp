#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string ans="1";
		string tmp;

		for (int i = 2; i <= n; ++i) {
			char count = '1';
			for (int j = 1; j < ans.size(); ++j) {
				if (ans[j] == ans[j - 1])
					count++;
				else {
					tmp+=count;
					tmp += ans[j - 1];
					count = '1';
				}
			}
			tmp += count;
			tmp += ans[ans.size() - 1];
			ans = tmp;
			tmp.clear();
		}
		
		return ans;
	}
};