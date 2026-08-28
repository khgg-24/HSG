#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("CAPCHAN.INP", "r", stdin);
    freopen("CAPCHAN.OUT", "w", stdout);

    long long n;
    cin >> n;
    long long chan = 0;
    long long le = 0;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if (x % 2 == 0) {
            chan++;
        } 
        else {
            le++;
        }
    }
    
    long long result = (chan * (chan - 1) / 2) + (chan * le);

    cout << result << "\n";

    return 0;
}
