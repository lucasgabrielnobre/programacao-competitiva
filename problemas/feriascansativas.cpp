#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d, c, r, cnt = 0; cin >> d >> c >> r;
    queue<int> C;
    for (int i = 0, x; i < c; i++)
    {
        cin >> x;
        C.push(x);
    }
    for (int i = 0, x; i < r; i++)
    {
        cin >> x;
        d += x;
    }
    cnt += r;
    while (!C.empty())
    {
        int ativC = C.front();
        if (d >= ativC)
        {
            d -= ativC;
            C.pop();
            cnt++;
        }
        else
            break;
    }
    cout << cnt << '\n';
}



