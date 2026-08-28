#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("CHONDOI.INP", "r", stdin);
    freopen("CHONDOI.OUT", "w", stdin);

    int N;
    cin >> N;
    long long cnt[5] = {};

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if (s[0] == 'H') {
            cnt[0]++;
        }
        else if (s[0] == 'S') {
            cnt[1]++;
        }
        else if (s[0] == 'G') {
            cnt[2]++;
        }
        else if (s[0] == 'P') {
            cnt[3]++;
        }
        else if (s[0] == 'T') {
            cnt[4]++;
        }
    }
    long long ans = 0;

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            for (int k = j + 1; k < 5; k++)
                ans += cnt[i] * cnt[j] * cnt[k];

    cout << ans << "\n";
    
    return 0;
}
