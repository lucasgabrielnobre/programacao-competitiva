#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(map<int, vector<int>>& grafo, int vertice, vector<int>& visitados)
{
    visitados[vertice] = 1;
    
    for (int vizinho : grafo[vertice])
    {
        if (visitados[vizinho] != 0)
            continue;
        dfs(grafo, vizinho, visitados);
    }
}

// se o vizinho não foi visitado guarda o vizinho e marca como visitado.
// Para cada elemento da fila realiza esse processo.
int cnt = 0;
void bfs(map<int, vector<int>>& grafo, int vertice, vector<int>& visitados, queue<int>& fila)
{
    fila.push(vertice); 
    visitados[vertice] = cnt;
    while (!fila.empty())
    {
        int V = fila.front(); // próximo vertice a ser checado
        fila.pop();
        for (int vizinho : grafo[V])
        {
            if (visitados[vizinho] == 0) // se eu não visitei esse vertice
            {
                visitados[vizinho] = cnt;
                fila.push(vizinho);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    map<int, vector<int>> grafo; // vertice e seus vizinhos
    for (int i = 1; i <= n; i++) grafo[i] = {};
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    vector<int> visitados(n + 1);
    queue<int> fila;
    for (int i = 1; i <= n; i++)
    {
        if (visitados[i] != 0)
            continue;
        cnt++;
        bfs(grafo, i, visitados, fila);

    }
    cout << cnt << '\n';

}

