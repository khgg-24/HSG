#include <bits/stdc++.h>
using namespace std;

vector<long long> cnt_div;

void count_divisors(int n) {
    cnt_div.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            cnt_div[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("CONGPHA.INP", "r", stdin);
    freopen("CONGPHA.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    int MAX = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > MAX) {
            MAX = a[i];
        }
    }

    count_divisors(MAX);
    long long kqua = 0;

    for (int i = 0; i < n; i++) {
        kqua += (a[i] * cnt_div[a[i]]);
    }
    
    cout << kqua << "\n";

    return 0;
}