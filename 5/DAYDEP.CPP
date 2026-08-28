#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("DAYDEP.INP", "r", stdin);
    freopen("DAYDEP.OUT", "w", stdin);

    int N;
    cin >> N;
    vector<int> cnt(1000001, 0);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int res = 0;

    for (int x = 0; x <= 1000000; x++) {
        if (cnt[x] > x) {
            res += cnt[x] - x;
        }
        else if ((cnt[x] > 0) && (cnt[x] < x)) {
            res += cnt[x];
        }
    }

    cout << res;
    
    return 0;
}