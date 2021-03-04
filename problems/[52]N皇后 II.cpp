#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int totalNQueens(int n) {
		vector<int> rows(n);
		int ans=0;
		dp(rows, 0, n, ans);

		return ans;
	}

	void dp(vector<int>& rows, const int n, const int& N, int& ans) {
		if (n == N) {
			++ans;
		}

		for (int j = 0; j < N; ++j) {
			bool flag = true;
			for (int i = 0; i < n; ++i)
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