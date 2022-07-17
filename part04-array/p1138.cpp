//
// Created by 24958 on 2022/7/17.
//
#include <iostream>
#include <algorithm>

using namespace std;
int n, k, a[10005];

int main ()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);                     // 降序 greater<int>()
    int n2 = unique(a, a + n) - a;      // unique(a, a + n) 表示去重    unique(a,a+n)-a表示去重后的元素个数
    // for (int i = 0; i < n2; ++i)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    if (k <= n2)
    {
        cout << a[k - 1];
    } else
    {
        cout << "NO RESULT";
    }
    return 0;
}