//
// Created by zyf on 2022/6/22.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> block[30];
int n;

void init();

void solve();

void print();


int main()
{
    init();
    solve();
    print();
    return 0;
}

void init()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        block[i].push_back(i);
    }
}

// 找位置
void loc(int x, int &p, int &h)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < block[i].size(); ++j)
        {
            if (block[i][j] == x)
            {
                p = i;
                h = j;
                return;
            }
        }
    }
}

// p堆 > h的所有块归位
void goback(int p, int h)
{
    for (int i = h + 1; i < block[p].size(); ++i)
    {
        int k = block[p][i];
        block[k].push_back(k);
    }
    block[p].resize(h + 1); // 重置大小
}

// p堆 >= h的所有块移动到 q之上
void moveall(int p, int h, int q)
{
    for (int i = h; i < block[p].size(); ++i)
    {
        int k = block[p][i];
        block[q].push_back(k);
    }
    block[p].resize(h); // 重置大小
}

void solve()
{
    int a, b;
    string s1, s2;
    while (cin >> s1)
    {
        if (s1 == "quit")
        {
            break;
        }
        cin >> a >> s2 >> b;
        int ap = 0, ah = 0, bp = 0, bh = 0;
        loc(a, ap, ah);
        loc(b, bp, bh);
        if (ap == bp)
        {
            continue;
        }
        if (s1 == "move") // a归位
        {
            goback(ap, ah);
        }
        if (s2 == "onto") // b归位
        {
            goback(bp, bh);
        }
        moveall(ap, ah, bp);
    }
}


void print()
{
    for (int i = 0; i < n; ++i)
    {
        cout << i << ":";
        for (int j = 0; j < block[i].size(); ++j)
        {
            cout << " " << block[i][j];
        }
        cout << endl;
    }
}