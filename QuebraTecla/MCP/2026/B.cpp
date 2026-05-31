#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n, k; cin >> n >> k;


    ll v = n;
    int x = 1;
    while (true)
    {
        if (v % k == 0)
        {
            break;
        }
        else
        {
            v += n;
            x++;
        }
    }
    cout << x << '\n';
}