#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 2e12;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        vector<ll> a(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
            
        ll minSum = 0;

        priority_queue<ll> pq;
        for (int i = 1; i <= m-1; i++)
        {
            minSum += a[i];
            pq.push(a[i]);
            
        }
        ll resp = -INF;

        for (int i = m; i <= n; i++)
        {
            resp = max(resp, a[i] * m - minSum);
            if (pq.size() > 0 && pq.top() > a[i]) // quer dizer que eu posso diminuir o minSum
            {
                ll major = pq.top();
                pq.pop();
                minSum -= major;
                minSum += a[i];
                pq.push(a[i]);
            }
        }
        cout << resp << '\n';
    }
}

