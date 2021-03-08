#include <cstdlib>
#include <stack>
using namespace std;
/*
	����һ������ת���⣬�ⷨ�ɷ����֣�ջ��˫ָ�롣
	���ڸ������ǹ涨ÿK��һ�鷴ת������k��������ʹ��˫ָ��Ļ������ڼ��������ѡ����ջ��
	��ȻҲ���Ա������Σ���һ�μ������ڶ��η�ת��
*/
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*
		�ݹ�
	*/
	ListNode* reverseKGroup(ListNode* head, int k) {
		stack<ListNode*> s;
		ListNode* p = head;
		for (int i = 0; p != NULL && i < k; ++i, p = p->next)
			s.push(p);
			
		if (s.size()<k)
			return head;

		ListNode* ac_head = s.top();
		ListNode* next = ac_head->next;
		s.pop();
		p = ac_head;
		while (!s.empty()) {
			p->next = s.top();
			s.pop();
			p = p->next;
		}
		p->next = reverseKGroup(next, k);

		return ac_head;
	}
};