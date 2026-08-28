#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, k;
vector<string> a;
long long C[1005][1005];

void build_C() {
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

void solve_sub1() {
    long long ans = 0;
    int total_subsets = 1 << n;

    for (int mask = 0; mask < total_subsets; mask++) {
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                for (int j = i + 1; j < n; j++) {
                    if ((mask >> j) & 1) {
                        if (a[i] == a[j]) pairs++;
                    }
                }
            }
        }
        if (pairs == k) {
            ans = (ans + 1) % MOD;
        }
    }

    cout << ans << "\n";
}

void solve_sub2() {
    map<string, int> freq;

    for (string s : a) {
        freq[s]++;
    }
    vector<int> cnt;
    cnt.push_back(0);

    for (auto it : freq) {
        cnt.push_back(it.second);
    }
    int m = cnt.size() - 1;
    vector<vector<long long>> f(m + 1, vector<long long>(k + 1, 0));
    f[0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x <= cnt[i]; x++) {
                int pairs_x = x * (x - 1) / 2;
                if (pairs_x > j) break; 
                long long ways_prev = f[i - 1][j - pairs_x];
                long long ways_curr = C[cnt[i]][x];
                f[i][j] = (f[i][j] + (ways_prev * ways_curr) % MOD) % MOD;
            }
        }
    }

    cout << f[m][k] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("CHONNHOM.INP", "r", stdin);
    freopen("CHONNHOM.OUT", "w", stdout);

    cin >> n >> k;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sort(a[i].begin(), a[i].end());
    }

    build_C();

    if (n <= 15) {
        solve_sub1();
    } else {
        solve_sub2();
    }

    return 0;
}