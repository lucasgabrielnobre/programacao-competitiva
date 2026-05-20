// vivo ou morto
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 1;
    while (true)
    {
        int p, r; cin >> p >> r;
        if (p == 0 && r == 0)
            break;
        queue<int> x; // fila inicial
        for (int i = 0, y; i < p; i++)
        {
            cin >> y;
            x.push(y);
        }
        for (int k = 0; k < r; k++)
        {
            int n; int j; cin >> n >> j;
            for (int i = 0; i < n; i++)
            {
                int a; cin >> a; // a ação do participante
                // se o participante não passou, ele é eliminado
                // se ele passou, ele vai pro final da fila.
                // perceba que a ordem não é perdida no final de uma rodada.
                if (a != j)
                {
                    x.pop();
                } 
                else
                {
                    int aux = x.front();
                    x.pop();
                    x.push(aux);
                }
            }
        }

        cout << "Teste " << cnt << '\n' << x.front() << "\n\n";
        cnt++;
    }
}
