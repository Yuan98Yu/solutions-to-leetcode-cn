#include <string>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string roman;

		int nums[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		const int SIZE = 13;

		for (int i = 0; i < SIZE; i++) {
			while (nums[i] <= num) {
				num -= nums[i];
				roman += romans[i];
			}
		}
		return roman;
	}
};