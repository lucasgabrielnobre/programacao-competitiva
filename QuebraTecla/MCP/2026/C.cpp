#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int e; int o; cin >> e >> o;
    set<string> E, O; string s;

    for (int i = 0; i < e; i++)
    {
        cin >> s;
        E.insert(s);
    }
    for (int i = 0; i < o; i++)
    {
        cin >> s;
        O.insert(s);
    }
    int qtdE = 0;
    int qtdO = 0;
    while(cin >> s)
    {
        char b = s.back();
        if (b == ',' || b == '.' || b == '?' || b == '!')
        {
            s.pop_back();
        }
        if (E.count(s) != 0)
            qtdE++;
        if (O.count(s) != 0)
            qtdO++;
    }
    if (qtdE > qtdO)
    {
        cout << "perto\n";
    }
    else if (qtdE < qtdO)
    {
        cout << "longe\n";
    }
    else
    {
        cout << "indeterminado\n";
    }
}