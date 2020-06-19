#include <iostream>
#include <string>
using namespace std;

string solve(string str) {
    string new_str = "";
    bool flag = false;
    size_t p_slice = 0;
    size_t p_same = 0;
    size_t i = 1;
    for (; i<str.size(); ++i) {
        if (str[i] != str[i-1]) {
            if (i-p_same >= 3) {
                new_str += str.substr(p_slice, p_same-p_slice);
                flag = true;
                p_slice = i;
            }
            p_same = i;
        }
    }
    if (i-p_same >= 3) {
        flag = true;
    }
    else if (p_slice < i) {
        new_str += str.substr(p_slice, i-p_slice);
    }
    // cout << new_str << endl;
    if (flag)
        return solve(new_str);
    else
        return new_str;
}

int main() {
    string tmp;
    cin >> tmp;
    cout << solve(tmp).size();
}