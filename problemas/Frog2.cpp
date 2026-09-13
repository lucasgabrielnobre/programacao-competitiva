#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> dp(n+1, 10e8);
    int h[n+1]; 
    int k; cin >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    if (k > n)
        k = n;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int jumps = min(i-1, k);
        for (int j = 1; j <= jumps; j++)
        {
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout << dp[n] << '\n';
}


