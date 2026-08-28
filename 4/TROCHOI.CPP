#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());
    long long min_val = 2e18;

    for (int i = 0; i < n; ++i) {
        long long target = -a[i];
        auto it = lower_bound(b.begin(), b.end(), target);

        if (it != b.end()) {
            min_val = min(min_val, abs(a[i] + *it));
        }
        if (it != b.begin()) {
            auto prev_it = it - 1;
            min_val = min(min_val, abs(a[i] + *prev_it));
        }
    }
    
    cout << min_val << "\n";

    return 0;
}
