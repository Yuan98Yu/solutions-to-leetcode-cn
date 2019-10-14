#include <cstdlib>
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
		if (root == nullptr || root->left == nullptr)
			return root;

		root->left->next = root->right;
		if (root->next != nullptr)
			root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
		return root;
	}
	Node* connect2(Node* root) {
		queue<Node*> q;
		if(root != nullptr)
			q.push(root);
		while (!q.empty()) {
			int len = q.size();
			Node* next = nullptr;
			for (int i = 0; i < len; ++i) {
				Node* cur = q.front();
				q.pop();
				if (cur->left != nullptr) {
					q.push(cur->right);
					q.push(cur->left);
				}
				cur->next = next;
				next = cur;
			}
		}
		return root;
	}
};