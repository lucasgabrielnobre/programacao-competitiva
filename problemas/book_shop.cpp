#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Livro
{
    int preco, paginas;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    //vector<vector<int> > dp(x+1, vector<int>(n)); 
    vector<int> dp(x+1, 0);
    Livro l[n];
    for (int i = 0; i < n; i++)
        cin >> l[i].preco; 
    for (int i = 0; i < n; i++)
        cin >> l[i].paginas;

    for (int i = 0; i < n; i++)
    {
        for (int j = x - l[i].preco; j >= 0; j--)
        {
            dp[j + l[i].preco] = max(dp[j] + l[i].paginas, dp[j + l[i].preco]);
        }
    }

    for (int i = 1; i <= x; i++)
    {
        cout << i << " " << dp[i] << '\n';
    }
    cout << dp[x] << '\n';
}

