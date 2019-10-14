#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		map<string, vector<string>> s2l;
		for (string s : strs) {
			string tmp = s;
			sort(tmp.begin(), tmp.end());
			s2l[tmp].push_back(s);
		}
		for (auto list : s2l) {
			ans.push_back(list.second);
		}

		return ans;
	}
};