/**
*	ʹ�ü��ϻ�map��ȷ�������ظ��ַ���ʹ��map�ĺô����ܹ������ַ����ַ����ֵ�λ�õ�ӳ��
*	�����ַ���256������ôʹ��һ��sizeΪ256��������Ϊmap���ɣ������ʹ��hashmap
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int map[256] = { 0 };
		int left = 1;
		int max_len = 0;
		if (s.size() > 0)
			max_len = 1;
		for (int i = 0; i < s.size(); i++) {
			if (map[s[i]] >= left) {
				if (i - left + 1 > max_len)
					max_len = i - left + 1;
				left = map[s[i]] + 1;
			}
			map[s[i]] = i + 1;
		}
		if (s.size() - left + 1 > max_len)
			max_len = s.size() - left + 1;
		return max_len;
	}
};
