//
// Created by zyf on 2022/6/23.
//

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    char c;
    stack<char> s;
    while (cin >> c && c != '@')
    {
        if (c == '(')
        {
            s.push(c);
        } else if (c == ')')
        {
            if (!s.empty())
            {
                s.pop();
            } else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
