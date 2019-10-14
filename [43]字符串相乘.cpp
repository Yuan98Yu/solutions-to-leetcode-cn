#include <string>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result(num1.length() + num2.length(), '0');
		for (int i = num2.length() - 1; i >= 0; --i) {
			mul_one(num1, num2[i], result, num1.length() + i);
		}

		int i = 0;
		for (; result[i] == '0' && i < result.length() - 1; ++i);
		result.erase(result.begin(), result.begin() + i);

		return result;
	}
private:
	void mul_one(const string& num, char dig, string& result, int end) {
		int carry = 0;
		int dig2 = dig - '0';
		for (int i = num.length() - 1; i >= 0; --i, --end) {
			int dig1 = num[i] - '0';
			int tmp_result = dig1 * dig2 + carry + result[end] - '0';
			result[end] = tmp_result % 10 + '0';
			carry = tmp_result / 10;
		}
		result[end] += carry;
	}
};