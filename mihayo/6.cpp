#include <iostream>
#include <string>
using namespace std;

int compute_value(string str)
{
    int value = (str.size()>0 ? 1 : 0);
    int tmp_value = 1;
    char flag = 'n';

    for (size_t i=1; i<str.size(); ++i)
    {
        char new_flag = 'n';
        if (str[i] == str[i - 1] + 1)
            new_flag = '+';
        else if (str[i] == str[i - 1] - 1)
            new_flag = '-';

        if ((new_flag == flag || flag == 'n') && new_flag != 'n')
        {
            tmp_value += 1;
            if (tmp_value > value)
                value = tmp_value;
        }
        else
            tmp_value = 1;

        flag = new_flag;
    }

    return value;
}

int main()
{
    // 读号码存入 vector
    string temp;
    cin >> temp;
    cout << compute_value(temp) << endl;
    return 0;
}