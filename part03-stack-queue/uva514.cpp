//
// Created by 24958 on 2022/7/16.
//
#include <iostream>
#include <stack>

using namespace std;
const int maxSize = 1000 + 5;
int n, B[maxSize];

int main ()
{
    while (cin >> n && n)
    {
        while (true)
        {
            int i = 1, j = 1;
            cin >> B[1];
            if (!B[1])
            {
                break;
            }
            for (int k = 2; k <= n; ++k)
            {
                cin >> B[k];
            }
            stack<int> s;
            while (i <= n)
            {
                if (i == B[j])
                {
                    ++i;
                    ++j;
                } else
                {
                    s.push(i++);
                }
                while (!s.empty() && s.top() == B[j])
                {
                    ++j;
                    s.pop();
                }
            }
            if (j <= n)
            {
                cout << "No" << endl;
            } else
            {
                cout << "Yes" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}