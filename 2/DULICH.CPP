#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("DULICH.INP", "r", stdin);
    freopen("DULICH.OUT", "w", stdout);

    int n;
    cin >> n;

    map<int, int> d;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b + 1]--;
    }

    int max_hoa = 0;
    int hoa_hien_tai = 0;

    for (auto item : d) {
        hoa_hien_tai += item.second; 
        max_hoa = max(max_hoa, hoa_hien_tai); 
    }

    cout << max_hoa << "\n";

    return 0;
}