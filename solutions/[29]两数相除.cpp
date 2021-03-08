#include <cstdlib>
/*
	1.	模拟除法的基本运算是减法；
		模拟列竖式算除法可再引入移位。
	2.	计算机中算减法是利用同余的性质
	3.	需注意计算机用补码表示有符号数，负数的个数比正数多1。
	4.	此题难点1为负数的除法， 2为优化
	5.	可能的优化：二分查找
*/
class Solution {
public:
	/*
		法1：只用减法
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