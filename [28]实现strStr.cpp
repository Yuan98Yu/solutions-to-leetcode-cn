#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/*
		1.����->str.find(str)
	*/
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		int pos = haystack.find(needle);
		return pos;
	}

	/*
		2.����
	*/
	int strStr2(string haystack, string needle) {
		if (needle.empty())
			return 0;

		int i = 0, j = 0;
		while (haystack[i] != '\0' && needle[j] != '\0')
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				i = i - j + 1;
				j = 0;
			}
		}
		if (needle[j] == '\0')
			return i - j;

		return -1;
	}

	/*
		3.KMP
		�˴�next[i]��ʾpattern[0]~pattern[i]���������ǰ��׺
	*/
	int* getNext(string pattern) {
		int len = pattern.length();
		int* next = new int[len];
		
		int j = 0;	//ǰ׺ĩβ�±�
		next[0] = 0;
		for (int i = 1; i < len; i++) {
			while (j > 0 && pattern[i] != pattern[j])
				j = next[j-1];
			if (pattern[i] == pattern[j])
				j++;

			next[i] = j;
		}
		return next;
	}

	int strStr3(string haystack, string needle) {
		if (needle.empty())
			return 0;

		int* next = getNext(needle);
		for (int i = 0, q = 0; i < haystack.length(); ++i) {
			while (q > 0 && haystack[i] != needle[q])
				q = next[q - 1];
			if (haystack[i] == needle[q])
				q++;
			if (q == needle.length())
				return i-q+1;
		}

		return -1;
	}

	/*
		4.KMPд��2
		��3������:next[i]��ʾ����pattern[i]ʧЧʱ��pattern���ݵ�λ�ã�����3�е�next����ƽ��1λ��
	*/
	int* getNext2(string pattern) {
		cout << pattern<<endl
			<<pattern.length()<<endl;
		int len = pattern.length();
		int* next = new int[len];

		next[0] = -1;	//��ֵ��Ϊ-1��Ϊ�˱�̷��㣬(-1)++ = 0 ��ʾ������ͷ
		int i = 0;
		int j = -1;
		while (i < len - 1) {
			if (j == -1 || pattern[j] == pattern[i]) {
				++i;
				++j;
				next[i] = j;
			}
			else {
				j = next[j];
			}
		}
		for (int i = 0; i < pattern.length(); ++i)
			cout << next[i] << " ";
		cout << endl;
		return next;
	}
	/*
		��ʱ�ɶ�next�������Ż�
	*/
	int* getNext3(string pattern) {
		int len = pattern.length();
		int* next = new int[len];

		int i = 1, j = -1;
		next[0] = -1;
		while (i < len - 1) {
			if (j == -1 || pattern[j] == pattern[i]) {
				++i;
				++j;
				if (j==-1 || pattern[j] != pattern[j - 1])
					next[i] = j;
				else
					next[i] = next[i - 1];
			}
			else {
				j = next[j];
			}
		}
		return next;
	}
	int strStr4(string haystack, string needle) {
		if (needle.empty())
			return 0;

		int* next = getNext3(needle);
		for (int i = 0, q = 0; i < haystack.length(); ++i) {
			while (q > 0 && haystack[i] != needle[q])
				q = next[q];
			if (haystack[i] == needle[q])
				q++;
			if (q == needle.length())
				return i - q + 1;
		}
		return -1;
	}
};