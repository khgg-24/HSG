#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("CHONNHOM.INP", "r", stdin);
    freopen("CHONNHOM.OUT", "w", stdout);

    int n;
    long long k;
    cin >> n >> k;

    string s;
    cin >> s;

    long long k_minus_1 = k - 1;
    int t = 0;

    while (k_minus_1 > 1) {
        k_minus_1 /= 2;
        t++;
    }

    string s1 = s + string(t, '0');
    string s2 = string(t, '0') + s;
    string result = "";
    int carry = 0;
    int len = s1.length();

    for (int i = len - 1; i >= 0; i--) {
        int bit1 = s1[i] - '0';
        int bit2 = s2[i] - '0';
        
        int sum = bit1 + bit2 + carry;
        
        result += to_string(sum % 2);
        carry = sum / 2;
    }
    if (carry > 0) {
        result += "1";
    }
    
    reverse(result.begin(), result.end());

    cout << result << "\n";

    return 0;
}