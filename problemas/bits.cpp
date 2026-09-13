#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;

    vector<ll> dp(n + 1);
    dp[0] = 1; 
    for (ll i = 1; i <= n; i++)
    {
        if (i < k)
        {
            dp[i] = (dp[i-1] << 1) % MOD;
        }
        else if (i == k)
        {
            dp[i] = ((dp[i-1] << 1) - 1 + MOD) % MOD; // exclui-se a possibilidade de todos serem 1
        }
        else if (i > k) 
        {
            // tira o caso de k-1 '1' no final + o '1' do novo bit
            dp[i] = (2*dp[i-1] - dp[i-k-1] + MOD) % MOD;
        }
        dp[i] %= MOD;
    }
    cout << dp[n] % MOD << '\n';
}

