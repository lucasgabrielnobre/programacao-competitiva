#include <bits/stdc++.h>
#include <queue>

using namespace std;
typedef long long ll;
int n;
const int MAXN = 100;
const int INF  = 1e9 + 10;

typedef pair<int, int> pii;
typedef pair<int, pii> cord; // w, x, y

int  d[MAXN][MAXN];
int  mina[MAXN][MAXN];
bool closed[MAXN][MAXN];

/*
8
00010000
11110011
11101111
00000110
11001110
11010100
01010000
01010100

8
01111111
11111101
11011111
11001111
11111111
11111011
01111111
11111110
*/ 
void dijkstra(int sx, int sy)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[j][i] = INF;
            closed[j][i] = false;
        }
    }
    d[sy][sx] = mina[sy][sx];
    priority_queue<cord, vector<cord>, greater<cord>> fila;
    fila.push({0, {sx, sy}});

    while (!fila.empty())
    {
        int x = fila.top().second.first;
        int y = fila.top().second.second;
        fila.pop();
        if (closed[y][x])
            continue;
        closed[y][x] = true;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int vx = x + dx[i];
            int vy = y + dy[i];
            if (vx >= n || vx < 0)
                continue;
            if (vy >= n || vy < 0)
                continue;

            if (d[vy][vx] > d[y][x] + mina[vy][vx]) // o obstaculo já é dito como 1, e vazio como 0
            {
                d[vy][vx] = d[y][x] + mina[vy][vx];
                fila.push({d[y][x] + mina[vy][vx], {vx, vy}});
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            mina[j][i] = c-'0';
        }
    }

    dijkstra(0, 0);
    cout << d[n-1][n-1] << '\n';
}

