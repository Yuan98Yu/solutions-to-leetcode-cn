#include <cstdlib>
#include <stack>
using namespace std;

class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node* child;

	Node() {}

	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	// ·¨1£ºµÝ¹é
	Node* flatten(Node* head) {
		dp(head, NULL);
		return head;
	}
	void dp(Node* head, Node* next) {
		if (head == NULL)
			return;
		if (head->child == NULL && head->next == NULL) {
			head->next = next;
			if (next != NULL)
				next->prev = head;
			return;
		}
		if (head->child) {
			Node* tmp = head->next;
			head->next = head->child;
			head->child->prev = head;
			dp(head->child, tmp);
			dp(tmp, next);
			head->child = NULL;
		}
		else
			dp(head->next, next);
	}

	// ·¨2£º µü´ú+Õ»
	Node* flatten2(Node* head) {
		stack<Node*> s;
		s.push(nullptr);
		s.push(head);
		Node* cur = head;
		while (!s.empty())
		{
			Node* cur = s.top();
			s.pop();
			for (; cur != nullptr; cur = cur->next) {
				if (cur->child != nullptr) {
					cur->child->prev = cur;
					if (cur->next != nullptr)
						s.push(cur->next);
					cur->next = cur->child;
					cur->child = nullptr;
				}
				else if (cur->next == nullptr) {
					cur->next = s.top();
					if (s.top() != nullptr)
						s.top()->prev = cur;
					s.pop();
				}
			}
		}
		return head;
	}
};