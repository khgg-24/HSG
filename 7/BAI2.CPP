#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);

    string s;
    cin >> s;
    int dem = 0;
    
    for (char i : s) {
        if (isdigit(i)) {
            dem++;
        }
    }

    cout << dem << "\n";

    return 0;
}