#include <queue>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node* connect(Node* root) {
		Node* cur = root;
		while (cur != nullptr) {
			Node* dummy = new Node(-1, nullptr, nullptr, nullptr);
			Node* tail = dummy;
			while (cur != nullptr) {
				if (cur->left != nullptr) {
					tail->next = cur->left;
					tail = tail->next;
				}
				if (cur->right != nullptr) {
					tail->next = cur->right;
					tail = tail->next;
				}
				cur = cur->next;
			}
			cur = dummy->next;
		}
		return root;
	}
};

