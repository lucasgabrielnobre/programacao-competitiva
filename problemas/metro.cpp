#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    int p[k]; 
    cin >> p[0]; int maior = p[0];
    for (int i = 1; i < k; i++)
    {
        cin >> p[i];
        if (p[i] > maior)
            maior = p[i];
    }

    int l = 0, r = maior;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        cnt += p[i] / r;
    }
    if (cnt == n)
    {
        cout << r;
        return 0;
    }
    int res = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            cnt += p[i] / m;
        }
        //cout << "L: " << l << " R: " << r << " M: " << m << " CNT: " << cnt << '\n';
        if (cnt > n) // é preciso aumentar m, muitos paes
        {
            res = max(res, m); // se for maior e não existir um antes, pega esse mesmo
            l = m + 1;
        }
        else if (cnt < n) // poucos paes, diminua o tamanho
        {
            r = m - 1;
        }
        else
        {
            // achou-se um valor que torna n, mas é preciso achar o maior, outra busca binária
            res = m;
            l = m + 1;
        }
    }
    cout << res << '\n';
}