#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int v[n];
    int s[n][10];
    cin >> v[0];
    for (int i = 0; i < 10; i++) s[0][i] = 0; // define o primeiro
    s[0][v[0]]++;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < 10; j++) s[i][j] = s[i-1][j];
        s[i][v[i]]++;
    }
    int cnt[10]; for (int i = 0; i < 10; i++) cnt[i] = 0; 
    int a; cin >> a; a--;
    for (int i = 1, b; i < m; i++)
    {
        cin >> b; b--;
        int l = min(a, b);
        int r = max(a, b);
        if (l > 0)
            for (int j = 0; j < 10; j++) cnt[j] += s[r][j] - s[l - 1][j];
        else
            for (int j = 0; j < 10; j++) cnt[j] += s[r][j];   
        if (i > 1)
            cnt[v[a]]--;
        a = b;
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << cnt[i] << " "; 
    }
}
