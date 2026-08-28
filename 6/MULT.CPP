#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("MULT.INP", "r", stdin);
    freopen("MULT.OUT", "w", stdout);

    int k;
    cin >> k;

    while (k--) {
        long long N, X;
        cin >> N >> X;
        
        if (N > X) {
            cout << 0 << "\n";
        }
        else {
            cout << X / N << "\n";
        }
    }

    return 0;
}