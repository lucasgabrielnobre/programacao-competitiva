#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int, int> pii;

const int maxn = 1e5 + 10;
const int INF = 1e9+10;

int n = 0, m = 0, c = 0, k = 0;

vector<int> d(maxn);
vector<int> p(maxn); 
vector<bool> closed(maxn, false);

vector<vector<pii>> grafo(maxn);

void dijkstra(int S)
{
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
        p[i] = -1;
        closed[i] = false;
    }
    d[S] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> fila;

    fila.push({0, S});

    while (!fila.empty())
    {
        int u = fila.top().second; 
        fila.pop();
        if (closed[u])
            continue;
        closed[u] = true;

        for (pii V : grafo[u]) 
        {
            int v = V.first; int w = V.second; 

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                p[v] = u;
                fila.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        cin >> n >> m >> c >> k;
        if (n == m && n == 0)
            break;

        grafo.assign(n, {});

        for (int i = 0; i < m; i++) 
        {
            int a, b, w;
            cin >> a >> b >> w;
            if (a > b) 
            {
                a = a^b;
                b = b^a;
                a = b^a;
            }
            if (a > c - 1 && b > c - 1)
            {
                // nao esta relaciando com a rota
                grafo[a].push_back({b, w});
                grafo[b].push_back({a, w});
            }
            else if (a <= c - 1 && b <= c - 1 && b == a + 1)
            {
                // direcional. 1 -> 2.
                grafo[a].push_back({b, w});
            }
            else if (a <= c - 1 && b > c - 1)
            {
                // direcional. 3 -> 0, 3 -> 2
                grafo[b].push_back({a, w});
            }
        }
        dijkstra(k);

        cout << d[c-1] << '\n';
    }
}

