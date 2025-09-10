// Author: Saikat_deb | Created: 2025-09-09 00:11
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    LL sum = 0;
    int ind = 0;
    while (ind < n) {
        if (a[ind] < 0) {
            int mx = INT_MIN;
            while (ind < n) {
                if (a[ind] > 0) {
                    break;
                }
                mx = max(mx, a[ind++]);
            }
            if (mx != INT_MIN) {
                // cout << mx << " ";
                sum += mx;
            }

        } else {
            int mx = INT_MIN;
            while (ind < n) {
                if (a[ind] < 0) {
                    break;
                }
                mx = max(mx, a[ind++]);
            }
            if (mx != INT_MIN) {
                // cout << mx << " ";
                sum += mx;
            }
        }
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}
