#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN (vector<string>& tokens) {
        stack<int> s;
        int i = 0;
        for (string str : tokens) {
            int is_op = __is_op(str);
            if (is_op == -1) {
                s.push(stoi(str));
            } 
            else {
                int op2 = s.top(); s.pop();
                int op1 = s.top(); s.pop();
                switch (is_op) {
                    case 0:
                        op1 += op2;
                        break;
                    case 1:
                        op1 -= op2;
                        break;
                    case 2:
                        op1 *= op2;
                        break;
                    case 3:
                        op1 /= op2;
                        break;
                }
                s.push(op1);
            }
        }
        return s.top();
    }
private:
    int __is_op (string str) {
        if (str == "+")
            return 0;
        else if (str == "-")
            return 1;
        else if (str == "*")
            return 2;
        else if (str == "/")
            return 3;
        else 
            return -1;
    }
};
