#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, pair<int, bool>> values;
class Sort
{
public:
    vector<string> numbers;

    Sort(const vector<string> &input_numbers)
    {
        for (int i = 0; i < input_numbers.size(); ++i)
        {
            pair<int, bool> value = compute_value(input_numbers[i]);
            if (value.first >= 3)
            {
                values[input_numbers[i]] = value;
                numbers.push_back(input_numbers[i]);
            }
        }
    }

    vector<string> my_sort()
    {
        stable_sort(numbers.begin(), numbers.end(), my_cmp);
        return numbers;
    }

    static bool my_cmp(const string &a, const string &b)
    {
        return values[a].first > values[b].first || (values[a].first == values[b].first && values[a].second && !values[b].second);
    }

    pair<int, bool> compute_value(string number)
    {
        int value = 0;
        bool is_baozi = false;
        int tmp_value = 1;
        char flag = 'n';

        for (int i = 4; i < 11; ++i)
        {
            char new_flag = 'n';
            if (number[i] == number[i - 1])
            {
                new_flag = '=';
            }
            else if (number[i] == number[i - 1] + 1)
            {
                new_flag = '+';
            }
            else if (number[i] == number[i - 1] - 1)
            {
                new_flag = '-';
            }

            if ((new_flag == flag || flag == 'n') && new_flag != 'n')
            {
                tmp_value += 1;
                if (tmp_value > value)
                {
                    value = tmp_value;
                    is_baozi = (new_flag == '=' ? true : false);
                }
                else if (tmp_value == value && new_flag == '=')
                {
                    is_baozi = true;
                }
            }
            else
            {
                tmp_value = 1;
            }

            flag = new_flag;
        }

        pair<int, bool> res;
        if (value >= 3)
            res = make_pair(value, is_baozi);
        else
            res = make_pair(0, is_baozi);

        return res;
    }
};

int main()
{
    // 读号码存入 vector
    vector<string> numbers;
    string temp;
    cin >> temp;
    int n = temp.length() / 12 + 1;
    for (int i = 0; i < n; i++)
    {
        numbers.push_back(temp.substr(12 * i, 11));
    }

    Sort mySort = Sort(numbers);
    vector<string> sorted_numbers = mySort.my_sort();

    // 输出结果
    if (sorted_numbers.size() > 0)
    {
        cout << sorted_numbers[0];
        for (int i = 1; i < sorted_numbers.size(); ++i)
            cout << "," << sorted_numbers[i];
    }
    else
    {
        cout << "null";
    }

    return 0;
}