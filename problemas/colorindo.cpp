#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAXN 201
struct P
{
    int x, y;
};
int n, m, x, y, k; 
int cnt = 0;
int img[MAXN][MAXN];
queue<P> q;
void dfs(P ponto)
{
    int x = ponto.x;
    int y = ponto.y;
    if (img[x][y] == 0)
        cnt++;
    img[x][y] = 1;
    // descobrir todos os vizinhos viaveis de x e y 
    int left   = x > 1 ? x - 1 : 1; 
    int right  = x < n ? x + 1 : n; 
    int top    = y > 1 ? y - 1 : 1;
    int bottom = y < m ? y + 1 : m;
    //cout << left << " " << right << " " << top << " " << bottom << '\n';
    vector<P> vizinhos;
    for (int i = left; i <= right; i++) 
    {
        for (int j = top; j <= bottom; j++)
        {
            if (img[i][j] == 0)
            {
                vizinhos.push_back( { i, j });
            }
        }
    }

    for (P vizinho : vizinhos)
    {
        dfs(vizinho);
    }
}
void bfs(P ponto)
{
    q.push(ponto);
    while (!q.empty())
    {
        P V = q.front();
        q.pop();
        int x = V.x;
        int y = V.y;
        int left   = x > 1 ? x - 1 : 1; 
        int right  = x < n ? x + 1 : n; 
        int top    = y > 1 ? y - 1 : 1;
        int bottom = y < m ? y + 1 : m;
        cnt++;
        img[x][y] = 1;
        for (int i = left; i <= right; i++) 
        {
            for (int j = top; j <= bottom; j++)
            {
                if (img[i][j] == 0)
                {
                    img[i][j] = 1;
                    q.push({ i, j });
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k; // x e y são as cordenadas onde comeca
    for (int i = 0; i <= n; i++) {for(int j = 0; j <= m; j++) {img[i][j] = 0;} }

    for (int i = 0; i < k; i++)
    {
        int a, b; cin >> a >> b;
        img[a][b] = 1;
    }

    bfs({ x, y });
    cout << cnt << '\n';

}

