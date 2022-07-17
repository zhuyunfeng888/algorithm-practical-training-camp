//
// Created by 24958 on 2022/7/17.
//
#include <iostream>

using namespace std;
int f[35], p[10];

int main ()
{
    int n, m, cnt = 0;
    cin >> n;
    for (int i = 1; i <= 7; ++i)
    {
        cin >> m;
        f[m] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt = 0;
        for (int j = 1; j <= 7; ++j)
        {
            cin >> m;
            if (f[m])
            {
                cnt++;
            }
        }
        p[cnt]++;
    }
    for (int i = 7; i > 1; --i)
    {
        cout << p[i] << " ";
    }
    cout << p[1];
    return 0;
}