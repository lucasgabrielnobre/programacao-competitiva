#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    ll n, k; cin >> n >> k;

    cout << ((n % k == 0) ? n/k : (n + k - 1)/k) << "\n";
}