#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Item
{
    ll weight = 0;
    ll value = 0;
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // w pode ir até 10⁹, passando do limite de tempo
    // vi e menor, vai até 10³
    ll n, w; cin >> n >> w;
    Item itens[n];
    vector<ll> dp(100001 , 1000000001); // vai até 100 * 10³ => 10⁵.
    dp[0] = 0;
    // value -> weight
    ll maxV = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> itens[i].weight;
        cin >> itens[i].value;
    }
    for (Item item : itens)
    {
        for (int j = maxV; j >= 0; j--) 
        {
            // pega o menor peso para aumentar ainda mais o valor
            dp[j + item.value] = min(dp[j + item.value], dp[j] + item.weight);
            // se existe uma combinação com esse valor e é menor que o limite
            if (dp[j + item.value] <= w) 
                maxV = max(maxV, j + item.value);
        }
    }
    cout << maxV << '\n';
}


