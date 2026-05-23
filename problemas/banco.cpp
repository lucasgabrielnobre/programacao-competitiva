// caixa
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, n; cin >> c >> n;
    priority_queue<int,vector<int>, greater<int>> caixas; 
    for (int i = 0; i < c; i++) caixas.push(0);
   
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int t, d; cin >> t >> d; 
        int C = caixas.top();
        caixas.pop();
        // se toda vez que eu for adicionar eu descontar o tempo atual, 
        // sempre vai ficar certo

        if (C < t) // se for menor vai ir para zero
            C = t;

        C -= t;
        if (C > 20)
            cnt++;
        
        caixas.push(C + d + t); // o + t serve para a diferença de tempo depois
    }
    cout << cnt << '\n';
}
