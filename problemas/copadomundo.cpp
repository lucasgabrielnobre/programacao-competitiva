// copa do mundo

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<char> players;
    for (char c = 'A'; c <= 'P'; c++)
    {
        players.push(c);
    }

    for (int i = 0; i < 15; i++)
    {
        int m, n; cin >> m >> n;

        if (m > n)
        {
            players.push(players.front()); // recoloca o vencedor
            players.pop(); // tira o vencedor
            players.pop(); // tira o perdedor
        }
        else // o vencedor é o segundo
        {
            players.pop(); // tira o perdedor
            players.push(players.front()); // recoloca o perdedor
            players.pop(); // tira o vencedor
        }
    }
    cout << players.front();
    /* 
    for (int j = 0; j < 15; j++)
    {
        int m, n; cin >> m >> n;
        if (m > n)

        {
            matches[j] = 0; // o da esquerda venceu
        }
        else
        {
            matches[j] = 1; // o da direita venceu
        }
    }
    
    int idx = 15;
    int lastRow = idx, nextRow = 0;
    int amount = 0; // quantidade para ir a direita
    for (int i = 1; i <= 3; i++)
    {
        int N = 1 << i;
        nextRow = lastRow - N;
        if (matches[idx - 1] == 1) // o atual aponta para a direita
        {
            amount++;
        }
        idx = nextRow + amount;
        amount *= 2;
        lastRow = nextRow;
    }
    cout << (char)(matches[idx - 1] + idx * 2 - 1 + 64);
    */
}
