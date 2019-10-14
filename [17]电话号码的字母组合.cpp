#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits.empty())
			return ans;

		ans.push_back("");
		unordered_map<char, string> mm = { {'2', "abc"},{'3',"def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
		for (auto digit : digits) {
			int len = ans.size();
			for (int i = 0; i < len; i++)
			{
				//按键的每个情况，在之前结果上加上一个按键
				for (auto m : mm[digit])
				{
					ans.push_back(ans[i] + m);
				}
			}
			//删除上一步中残留的项
			ans.erase(ans.begin(), ans.begin() + len);
		}
		return ans;
	}

	// 递归版本
	// 驱动函数
	vector<string> rec_comb(string digits) {
		vector<string> ans;
		if (digits.empty())
			return ans;

		unordered_map<char, string> mm = { {'2', "abc"},{'3',"def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
		rec(ans, mm, "", digits);
		return ans;
	}
	// 递归函数
	void rec(vector<string>& ans, unordered_map<char, string>& mm, const string& str, const string& remaining) {
		if (remaining.empty()) {
			ans.push_back(str);
			return;
		}

		for (auto c : mm[remaining[0]]) {
			rec(ans, mm, str + c, remaining.substr(1));
		}
	}
};