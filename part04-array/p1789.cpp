//
// Created by 24958 on 2022/7/18.
//
#include <iostream>

using namespace std;
bool g[10000][10000];
int n, m, k;
int x, y;

void light (int x, int y, int t)
{
    for (int i = x - t; i <= x + t; ++i)                // 上下各五层
    {
        for (int j = y - t; j <= y + t; ++j)
        {
            if (i > n || i < 1 || j > n || j < 1)       // 如果超过范围就跳过
            {
                continue;
            } else
            {
                g[i][j] = 1;                            // 否则标记
            }
        }
    }
}

void ys (int x, int y)
{
    light(x, y, 2);
}

void hb (int x, int y)
{
    light(x, y, 1);
    if (x + 2 <= n)
    {
        g[x + 2][y] = 1;
    }
    if (x - 2 > 0)
    {
        g[x - 2][y] = 1;
    }
    if (y + 2 <= n)
    {
        g[x][y + 2] = 1;
    }
    if (y - 2 > 0)
    {
        g[x][y - 2] = 1;
    }
}

int count ()
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (g[i][j] == 0)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main ()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y;
        hb(x, y);
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> x >> y;
        ys(x, y);
    }
    cout << count();
    return 0;
}