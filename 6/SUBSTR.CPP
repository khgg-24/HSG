#include <bits/stdc++.h>
using namespace std;

void sub1(int a, string b) {
    int n = b.length();
    int ans = 0;

    for (int L = 0; L < n; L++) {
        int cnt = 0;

        for (int R = L; R < n; R++) {
            if (b[R] == '1') {
                cnt++;
            }
            if (cnt == a) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

void sub2(int a, string b) {
    int n = b.length();

    vector<int> pre(n + 1, 0);

    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + (b[i] - '0');
    }

    int ans = 0;

    for (int L = 0; L < n; L++) {
        for (int R = L; R < n; R++) {
            int res = pre[R + 1] - pre[L];

            if (res == a) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

void sub3(int a, string b) {
    int n = b.length();

    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (b[i] == '1') {
            p.push_back(i);
        }
    }

    int m = p.size();
    if (a == 0) {
        long long ans = 0;
        int len = 0;

        for (int i = 0; i < n; i++) {
            if (b[i] == '0') {
                len++;
            }
            else {
                ans += 1LL * len * (len + 1) / 2;
                len = 0;
            }
        }

        ans += 1LL * len * (len + 1) / 2;

        cout << ans << "\n";

        return;
    }
    if (m < a) {
        cout << 0 << "\n";
        
        return;
    }

    long long ans = 0;
    for (int i = 0; i + a - 1 < m; i++) {
        int L;

        if (i == 0)
            L = p[i] + 1;
        else
            L = p[i] - p[i - 1];

        int R;

        if (i + a == m)
            R = n - p[i + a - 1];
        else
            R = p[i + a] - p[i + a - 1];

        ans += 1LL * L * R;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("SUBSTR.INP", "r", stdin);
    freopen("SUBSTR.OUT", "w", stdout);

    int k;
    cin >> k;

    string s;
    cin >> s;

    if (k <= 100 && s.length() <= 100) {
        sub1(k, s);
    }
    else if (k <= 254 && s.length() <= 254) {
        sub2(k, s);
    }
    else {
        sub3(k, s);
    }

    return 0;
}