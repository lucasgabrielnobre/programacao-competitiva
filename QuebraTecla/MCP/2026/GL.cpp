#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n; cin >> n;
    int a[n];
    int naoZero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        
        if (a[i] <= naoZero && naoZero != 0 && a[i] != 0) // se houve crescimento
        {
            cout << "nao\n";
            return 0;
        }    
        if (a[i] != 0)
            naoZero = a[i];
    }
    int zeros = 0; 
    naoZero = 0;
    
    for (int i = 0; i < n; i++)
    {   
        //cout << "I: " << i << " AI: " << a[i] << " naoZero: " << naoZero << " Zeros: " << zeros << '\n'; 
        if (a[i] == 0)
            zeros++;
        else
        {
            if (a[i] - naoZero - 1 < zeros)
            {
                
                cout << "nao\n";
                return 0;
            }
            zeros = 0;
        }
        if (a[i] != 0)
        {
            naoZero = a[i];
        }
    }
    cout << "sim\n";
}