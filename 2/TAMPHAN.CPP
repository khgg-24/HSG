#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long f[100005][3]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("TAMPHAN.INP", "r", stdin);
    freopen("TAMPHAN.OUT", "w", stdout);
    
    int n;
    cin >> n;

    f[1][0] = 1;
    f[1][1] = 1;
    f[1][2] = 1;

    for (int i = 2; i <= n; i++) {
        f[i][0] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % MOD;
        
        f[i][1] = (f[i - 1][0] + f[i - 1][2]) % MOD;
        
        f[i][2] = (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % MOD;
    }

    long long ans = (f[n][0] + f[n][1] + f[n][2]) % MOD;
    
    cout << ans << "\n";

    return 0;
}