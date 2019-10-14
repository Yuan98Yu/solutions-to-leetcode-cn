#include <cstdlib>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	/*
		���������ڵ㣬ʵ�����迼���������ڽڵ�
		�ݹ�д��
	*/
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* ac_head = head->next;

		ListNode* forward = head->next;
		head->next = forward->next;
		forward->next = head;
		head->next = swapPairs(head->next);

		return ac_head;
	}
	/*
		ѭ��д��
		������·������һ��ͷ�ڵ��Լ��ٱ�̵Ĺ�����
	*/
	ListNode* swapPairs2(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;

		ListNode* dummy = new ListNode(0);
		dummy->next = head;
		ListNode* p = dummy;

		while (p->next != NULL && p->next->next != NULL) {
			ListNode* p1 = p->next;
			ListNode* p2 = p1->next;
			p->next = p2;
			p1->next = p2->next;
			p2->next = p1;
			p = p1;
		}

		return dummy->next;
	}
};