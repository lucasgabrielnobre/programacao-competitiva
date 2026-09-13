#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;

ll n, m;
const ll MAXN = 1010;
const ll INF  = 1e9 + 10;

vector<bool> closed(MAXN, false);
vector<ll>  d(MAXN, INF);
vector<vector<pll> > grafo(MAXN); // u => v, w;

void dijkstra(int S)
{
    d[S] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> fila;

    fila.push({0, S});

    while(!fila.empty())
    {
        ll u = fila.top().second;
        fila.pop();
        if (closed[u])
            continue;
        closed[u] = true;

        for (pll V : grafo[u])
        {
            int v = V.first; int w = V.second;

            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                fila.push({d[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        ll s, t, b; cin >> s >> t >> b;

        grafo[s].push_back({t, b});
        grafo[t].push_back({s, b});
    }
    dijkstra(0);
    cout << d[n+1] << '\n';
}

