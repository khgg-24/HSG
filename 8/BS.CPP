#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("BS.INP", "r", stdin);
    freopen("BS.OUT", "w", stdout);

    long long n, x; 
    cin >> n >> x;
    int dem = 0;

    for (long long i = 1; i <= n && i <= x; i++) {
        if (x % i == 0) {
            long long j = x / i;
            
            if (j <= n) {
                dem++;
            }
        }
    }

    cout << dem << "\n";

    return 0;
}