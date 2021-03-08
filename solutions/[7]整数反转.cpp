#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int rev = 0;//��ŷ�ת�����
		int pop = 0;//��ŵ�������
		while (x != 0)
		{
			pop = x % 10;//������������ȡ�����з�ת
			x /= 10;
			if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && pop > 7) //�ж�����
				return 0;
			if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && pop < -8) //�ж�����
				return 0;
			rev = rev * 10 + pop;
		}
		return rev;
	}

	int reverse2(int x) {
		long long_x;
		string str_x = to_string(x);//������ת�����ַ���
		int pos = str_x.find_first_not_of("-");
		//�ҵ���һ���롮-����ƥ����ַ�λ��

		std::reverse(str_x.begin() + pos, str_x.end());
		//��������λ�����ֽ��з�ת

		stringstream out(str_x);
		out >> long_x;//��stringת����long�洢��long_x��
		if (long_x > INT_MAX || long_x < INT_MIN)
			return 0;
		return long_x;
	}
};
