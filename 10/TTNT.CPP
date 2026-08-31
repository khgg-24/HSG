#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("TTNT.INP", "r", stdin);
    freopen("TTNT.OUT", "w", stdout);

    long long X, S, T;
    cin >> X >> S >> T;
    long long a = X + S;
    long long b = T % a;

    if ((b <= X) && (b != 0)) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }

    return 0;
}