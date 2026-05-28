#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int a[n - 1];
    int f[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    for (int i = 0, o; i < m; i++)
    {
        cin >> o;
        cout << f[upper_bound(a, a + n - 1, o) - a] << " ";
    }
}