#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	/*
		��1����¼��ǰ�������ź������ŵ�������
			��ǰ�������������ڵ�������������ʱ���Ϸ���
			���򣬷Ƿ���
		����Ϊ�ݹ����
	*/
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if (n == 0)
			return ans;
		dp(ans, n - 1, n, "(");
		return ans;
	}

	void dp(vector<string>& ans, int l_remain, int r_remain, string str) {
		if (l_remain == 0 && r_remain == 0) {
			ans.push_back(str);
			return;
		}

		if (l_remain > 0)
			dp(ans, l_remain - 1, r_remain, str + '(');
		if (l_remain < r_remain)
			dp(ans, l_remain, r_remain - 1, str + ')');
	}
	/*
	��2����ÿ�����ɵ����з�Ϊleft��right�����֣���left��rightΪ�Ϸ��ģ�������ַ����Ϸ�����
		Ҫ�������ţ����ҳ�ÿһ�ԺϷ���left��right������ÿ��left�����߼��������š�
	��дΪ�ݹ�����趯̬�滮����
	*/
};