#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("KHOASO.INP", "r", stdin);
    freopen("KHOASO.OUT", "w", stdout);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int A = abs(a - 2);
    int B = b;
    int C = abs(c - 2);
    int D = abs(d - 5);

    int ans = min(A, 10 - A) + min(B, 10 - B) + min(C, 10 - C) + min(D, 10 - D);

    cout << ans << "\n";

    return 0;
}