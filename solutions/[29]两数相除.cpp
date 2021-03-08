#include <cstdlib>
/*
	1.	ģ������Ļ��������Ǽ�����
		ģ������ʽ���������������λ��
	2.	������������������ͬ�������
	3.	��ע�������ò����ʾ�з������������ĸ�����������1��
	4.	�����ѵ�1Ϊ�����ĳ����� 2Ϊ�Ż�
	5.	���ܵ��Ż������ֲ���
*/
class Solution {
public:
	/*
		��1��ֻ�ü���
	*/
	const int MAX = pow(2, 31) - 1;
	const int MIN = -MAX - 1;

	int divide(int dividend, int divisor) {
		long long count = 1;

		bool is_negetive = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor>0));
		long long l_dividend = dividend;
		long long l_divisor = divisor;
		l_dividend = abs(l_dividend);
		l_divisor = abs(l_divisor);
		if (l_dividend < l_divisor)
			return 0;
		else if (l_dividend == l_divisor)
			count = 1;
		else {
			while (l_dividend > l_divisor) {
				count <<= 1;
				l_divisor <<= 1;
			}
			if (l_dividend < l_divisor)
				count = (count >> 1) + divide(l_dividend - (l_divisor >> 1), abs(divisor));
		}
		if (is_negetive)
			count = -count;

		if (count > MAX || count < MIN)
			return MAX;
		return count;
	}
};