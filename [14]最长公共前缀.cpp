#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans = "";
		if (strs.empty())    return ans; //����Ϊ�գ������ans
		int arr = strs.size();
		string min = strs[0];
		for (int i = 1; i < arr; ++i) //�ҵ�����ַ���
		{
			if (strs[i].size() < min.size())
				min = strs[i];
		}
		for (int j = 0; j < min.size(); ++j) //�ӵ�һ���ַ���ʼ�Աȣ�����һ����ans���ϸ��ַ�������һ�������ش𰸣�
		{
			for (int m = 0; m < arr; ++m)
			{
				if (min[j] != strs[m][j])
					return min.substr(0, j);
			}
		}
		return min;
	}
};