// soma de prefixo e busca binária
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;

    int a[n];
    int s[n];
    cin >> a[0]; s[0] = a[0];
    
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    ll cnt = 0; // pegar o lower e upper bound
    // lower bound -> menor indice i tal que ai == x
    // upper bound -> menor indice i tal que ai > x
    // upper - lower => número de valores == x
    // s[l, i] == s[i] - s[l - 1]
    // achar um l tal que => s[l, s[i]] == k
    // s[i] - k == s[l - 1]
    for (int i = 0; i < n; i++)
    {
        if (s[i] < k)
            continue;
        if (s[i] == k)
            cnt++;
        int upper = upper_bound(s, s + i, s[i] - k) - s;
        int lower = lower_bound(s, s + i, s[i] - k) - s;
        cnt += upper - lower;
        //cout << upper << " " << lower << " " << s[i] - s[lower] << " " <<s[i] - s[upper] << '\n';
    }
    cout << cnt << '\n';
}