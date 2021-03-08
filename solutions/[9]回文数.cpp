#include <iostream>
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int input = x;

		int rev = 0;//存放反转后的数
		int pop = 0;//存放弹出的数
		while (x != 0)
		{
			pop = x % 10;//从右往左依次取数进行反转
			x /= 10;
			if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && pop > 7) //判断上限
				return 0;
			if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && pop < -8) //判断下限
				return 0;
			rev = rev * 10 + pop;
		}
		return rev == input;
	}
};