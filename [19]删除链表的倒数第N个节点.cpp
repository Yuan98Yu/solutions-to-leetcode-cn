#include <cstdlib>
// definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		/*	
			��Ҫ���ǵı߽������
				1.n��Ч��Ȼ����Ŀ��֤��n��Ч),
				2.����ֻ��1���ڵ�
				3.ɾ����������ĵ�һ���ڵ�
			���2��3����򵥷���������ͷ�ڵ㣻���������߽��顣
		*/
		ListNode* dummy = new ListNode(0);
		dummy->next = head;

		ListNode* forward = head;
		ListNode* rear = dummy;
		for (int i = 0; i < n-1; i++, forward = forward->next);
		for (; forward->next != NULL; rear = rear->next, forward=forward->next);
		forward = rear->next;
		rear->next = forward->next;
		delete forward;

		return dummy->next;
	}
};