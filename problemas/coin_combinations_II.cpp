#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007
#define MAXV 1000001
vector<ll> dp(MAXV);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    dp[0] = 1;   
    for (ll i = 0; i < n; i++)
    {
        for (ll j = c[i]; j <= x; j++)
        {
            dp[j] += dp[j-c[i]] % MOD;
        }
    }

    cout << dp[x] % MOD << '\n';
}

