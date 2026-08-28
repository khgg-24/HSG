#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> a(m);
    
    for (int i = 0; i < m; i++) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end(), greater<pair<long long, long long>>());

    long long res = 0;
    for (int i = 0; i < m; i++) {
        long long take = min(n, a[i].second);
        res += take * a[i].first;
        n -= take;
        
        if (n == 0) break; 
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("CHONBI.INP", "r", stdin);
    freopen("CHONBI.OUT", "w", stdin);

    solve();
    
    return 0;
}