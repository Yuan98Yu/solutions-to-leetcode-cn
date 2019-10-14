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
				//������ÿ���������֮ǰ����ϼ���һ������
				for (auto m : mm[digit])
				{
					ans.push_back(ans[i] + m);
				}
			}
			//ɾ����һ���в�������
			ans.erase(ans.begin(), ans.begin() + len);
		}
		return ans;
	}

	// �ݹ�汾
	// ��������
	vector<string> rec_comb(string digits) {
		vector<string> ans;
		if (digits.empty())
			return ans;

		unordered_map<char, string> mm = { {'2', "abc"},{'3',"def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
		rec(ans, mm, "", digits);
		return ans;
	}
	// �ݹ麯��
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