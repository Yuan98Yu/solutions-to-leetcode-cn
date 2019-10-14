#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> rows(n);
		vector<vector<string>> ans;
		dp(rows, 0, n, ans);

		return ans;
	}

	void dp(vector<int>& rows, const int n, const int& N, vector<vector<string>>& ans) {
		if (n == N) {
			vector<string> tmp;
			for (int i = 0; i < N; ++i) {
				string row;
				for (int j = 0; j < rows[i]; ++j)
					row += '.';
				row += 'Q';
				for (int j = rows[i] + 1; j < N; ++j)
					row += '.';
				tmp.push_back(row);
			}
			ans.push_back(tmp);
			return;
		}

		for (int j = 0; j < N; ++j) {
			bool flag = true;
			for(int i=0;i<n;++i)
				if (rows[i] == j || rows[i] + i == j + n || rows[i] - i == j - n) {
					flag = false;
					break;
				}
			if (flag) {
				rows[n] = j;
				dp(rows, n + 1, N, ans);
			}
		}
	}
};