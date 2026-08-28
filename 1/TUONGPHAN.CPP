#include <bits/stdc++.h>
using namespace std;

void solve_subtask1(int n, int p, const vector<int>& a) {
    int ans = 0;
    for (int i = 1; i <= n; i += 3) {
        int max_val = max({a[i], a[i+1], a[i+2]});
        int min_val = min({a[i], a[i+1], a[i+2]});
        ans = max(ans, max_val - min_val);
    }

    cout << ans << "\n";
}

void solve_subtask2(int n, int p, vector<int> a) {
    sort(a.begin() + 1, a.end());
    int ans = 2e9;

    for (int i = 1; i <= n - 2; ++i) {
        ans = min(ans, a[i+2] - a[i]);
    }

    cout << ans << "\n";
}
bool check(int x, int n, int p, const vector<int>& a) {
    vector<int> dp(n + 1, 0);

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (a[i] - a[i - 2] <= x) {
            dp[i] = max(dp[i], dp[i - 3] + 1);
        }
    }

    return dp[n] >= p; 
}

void solve_subtask3(int n, int p, vector<int> a) { 
    sort(a.begin() + 1, a.end());
    int l = 0;
    int r = a[n] - a[1];
    int ans = -1;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        
        if (check(mid, n, p, a)) {
            ans = mid;
            r = mid - 1; 
        } 
        else {
            l = mid + 1; 
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("TUONGPHAN.INP", "r", stdin);
    freopen("TUONGPHAN.OUT", "w", stdout);
    
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (3 * p == n) {
        solve_subtask1(n, p, a);
    } 
    else if (p == 1) {
        solve_subtask2(n, p, a);
    } 
    else {
        solve_subtask3(n, p, a);
    }
    
    return 0;
}