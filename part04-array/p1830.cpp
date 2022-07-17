//
// Created by 24958 on 2022/7/17.
//
#include <iostream>                             // 如果使用 万能头文件，不能定义 y1, y1[]

using namespace std;
const int size = 10002;
int x1[size], y1[size], x2[size], y2[size];     // 保存轰炸的四角

int main ()
{
    int n, m, x, y, a, b;
    cin >> n >> m >> x >> y;
    for (int i = 0; i < x; ++i)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }
    int cnt = 0, last = 0;
    for (int i = 0; i < y; ++i)
    {
        cin >> a >> b;
        cnt = 0;
        for (int j = 0; j < x; ++j)
        {
            if (a >= x1[j] && a <= x2[j] && b >= y1[j] && b <= y2[j])
            {
                cnt++;
                last = j;
            }
        }
        if (!cnt)
        {
            cout << "N" << endl;
        } else
        {
            cout << "Y " << cnt << " " << ++last << endl;
        }
    }
    return 0;
}
