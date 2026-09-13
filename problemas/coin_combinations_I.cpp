#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define MAXV 1000001

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    ll c[n];
    vector<ll> dp(MAXV);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    dp[0] = 1;
    // para cada moeda testar todos os valores de moeda
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - c[j] >= 0)
                dp[i] += dp[i-c[j]] % MOD;
        }
    }
    cout << dp[x] % MOD << '\n';
}

