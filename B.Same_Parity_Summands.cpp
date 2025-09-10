// Author: Saikat_deb | Created: 2025-09-08 23:44
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n & 1) {
        if (k & 1) {
            int res = 0;
            for (int i = 1; i <= 100; i++) {
                int rem = n - ((k - 1) * i);
                if ((i & 1 and rem & 1) or (i % 2 == 0 and rem % 2 == 0)) {
                    res = i;
                    break;
                }
            }
            if ((n - ((k - 1) * res)) < 0)
                cout << "NO\n";
            else {
                cout << "YES\n";
                for (int i = 0; i < k - 1; i++)
                    cout << res << " ";
                cout << n - ((k - 1) * res) << "\n";
            }
        } else {
            cout << "NO\n";
        }
    } else {
        if (k <= n / 2) {
            int res = 0;
            for (int i = 1; i <= 100; i++) {
                int rem = n - ((k - 1) * i);
                if ((i & 1 and rem & 1) or (i % 2 == 0 and rem % 2 == 0)) {
                    res = i;
                    break;
                }
            }
            if ((n - ((k - 1) * res)) < 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                for (int i = 0; i < k - 1; i++)
                    cout << res << " ";
                cout << n - ((k - 1) * res) << "\n";
            }
        } else {
            if (k & 1) {
                cout << "NO\n";
            } else {
                int res = 0;
                for (int i = 1; i <= 100; i++) {
                    int rem = n - ((k - 1) * i);
                    if ((i & 1 and rem & 1) or (i % 2 == 0 and rem % 2 == 0)) {
                        res = i;
                        break;
                    }
                }
                if ((n - ((k - 1) * res)) < 0) {
                    cout << "NO\n";
                } else {
                    cout << "YES\n";
                    for (int i = 0; i < k - 1; i++)
                        cout << res << " ";
                    cout << n - ((k - 1) * res) << "\n";
                }
            }
        }
    }
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
