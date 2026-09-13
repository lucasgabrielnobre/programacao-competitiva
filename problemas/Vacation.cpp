#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; 
    vector<vector<int> > dp(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        int a[3]; cin >> a[0] >> a[1] >> a[2];
        if (i == 0)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = a[j];
            }
            continue;
        }
        for (int j = 0; j < 3; j++) // preenchimento de todas as escolhas do dia i
        {
            dp[i][j] = a[j];
            for (int k = 0; k < 3; k++) // para cada dia, pegar o melhor atividade do dia anterior (sem repetir)
            {
                if (k == j)
                    continue;
                dp[i][j] = max(dp[i][j], a[j] + dp[i-1][k]); // o melhor da atividade de hoje mais uma anterior
            }
        }
        //cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] <<  '\n';
    }
    cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << '\n';
}

