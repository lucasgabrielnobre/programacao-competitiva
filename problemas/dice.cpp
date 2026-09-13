#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll dp[MOD];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    dp[1] = 1;
    ll sum = dp[1];
    // a partir de um soma i, é possível fazer a soma de
    // i - 6 até i - 1, ou seja, 6 possibilidades.
    // deve-se somar com o somatório das possibilidades anteriores, de dp[i-1] até dp[i-6]
    // se i > 7
    // dp[2] + dp[3] + dp[4] + dp[5] + dp[6] + dp[7] = dp[8]
    // dp[1] + dp[2] + dp[3] + dp[4] + dp[5] + dp[6] = dp[7]
    // se i <= 7
    // dp[1] + dp[2] + dp[3] + dp[4] + 1 (proprio dado) = dp[5]
    for (ll i = 2; i <= n; i++)
    {
        if (i > 7)
            sum -= dp[i-7] % MOD;
        dp[i] = sum; // dp[i] == dp[i - 1] + ... + dp[i - 7]
        if (i <= 6) // precisa contar o caso do próprio número
        {
            dp[i]++;
        }
        sum += dp[i] % MOD;
    }
    cout << dp[n] % MOD<< '\n';
}
