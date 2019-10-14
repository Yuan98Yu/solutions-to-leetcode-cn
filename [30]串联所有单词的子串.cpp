#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ans;
		if (words.empty() || s.empty())
			return ans;
		map<string, int> m1;
		map<string, int> m2;
		int word_len = words[0].length();
		int word_num = words.size();
		for (string str : words) {
			++m1[str];
		}
		for (int i = 0; i <= s.length() - word_num * word_len; ++i) {
			int j = 0;
			for (j = i; j < i + word_num * word_len; j += word_len) {
				string tmp = s.substr(j, word_len);
				if (m1[tmp] == 0)
					break;
				else {
					++m2[tmp];
					if (m2[tmp] > m1[tmp])
						break;
				}
			}
			if (j == i + word_len * word_num)
				ans.push_back(i);
			m2.clear();
		}
		return ans;
	}
};