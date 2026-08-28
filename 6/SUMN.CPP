#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("SUMN.INP", "r", stdin);
    freopen("SUMN.OUT", "w", stdout);

    string s;
    cin >> s;
    long long ans = 0;
    
    for (auto c : s) {
        ans += c - '0';
    }
    cout << ans << "\n";

    return 0;
}