//
// Created by 24958 on 2022/7/17.
//
#include <iostream>

using namespace std;
string s1, s;

int main ()
{
    int n, cnt = 1;
    cin >> s;
    n = s.size();
    cout << n;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> s1;
        s += s1;
    }
    if (s[0] == '1')
    {
        cout << " " << 0;
    }
    for (int i = 0; i < n * n; ++i)
    {
        if (s[i] == s[i + 1])
        {
            cnt++;
        } else
        {
            cout << " " << cnt;
            cnt = 1;
        }
    }
    cout << endl;
    return 0;
}