#include <bits/stdc++.h>
using namespace std;

const int MAX_SUM = 100005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total_sum += a[i];
    }

    vector<int> dp(total_sum + 1, -1);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        vector<int> next_dp = dp; 
        
        for (int j = 0; j <= total_sum; j++) {
            if (dp[j] != -1) {
                if (j + x <= total_sum) {
                    next_dp[j + x] = max(next_dp[j + x], dp[j] + x);
                }
                if (x <= j) {
                    next_dp[j - x] = max(next_dp[j - x], dp[j]);
                } else {
                    next_dp[x - j] = max(next_dp[x - j], dp[j] - j + x);
                }
            }
        }
        dp = next_dp;
    }

    cout << dp[0] << "\n";

    return 0;
}