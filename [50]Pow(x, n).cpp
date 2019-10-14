class Solution {
public:
	double binary_pow(double x, int n) {
		if (n == 0)
			return 1.0;
		if (n == 1)
			return x;
		if (n % 2 == 0)
			return binary_pow(x * x, n / 2);
		else
			return binary_pow(x * x, n / 2) * x;
	}
	double myPow(double x, int n) {
		long e = n;
		if (e < 0) {
			x = 1 / x;
			e = -e;
		}

		return binary_pow(x, e);
	}
};