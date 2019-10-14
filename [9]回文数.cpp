#include <iostream>
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int input = x;

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
		return rev == input;
	}
};