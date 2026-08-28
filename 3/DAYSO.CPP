#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);

    long long n, kqua = 0;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        kqua += i;
    }
    cout << kqua << "\n";
    return 0;
}