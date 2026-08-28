#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("DAYSO.INP", "r", stdin);
    freopen("DAYSO.OUT", "w", stdout);

    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;

    for (char c : s) {
        if (c == '0') {
            cnt++;
            ans = max(ans, cnt);
        } 
        else {
            cnt = 0;
        }
    }

    cout << ans << "\n";
}