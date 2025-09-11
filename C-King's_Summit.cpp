// Author: Saikat_deb | Created: 2025-09-11 21:33
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
void solve() {
    int n;
    cin >> n;
    vector<pair<LL, LL>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    LL rmx = 0, cmx = 0, rmn = LLONG_MAX, cmn = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        LL v1 = a[i].first, v2 = a[i].second;
        rmx = max(rmx, v1);
        rmn = min(rmn, v1);
        cmx = max(cmx, v2);
        cmn = min(cmn, v2);
    }
    LL m1 = (LL)floor((rmx + rmn) / 2.0);
    LL m2 = (LL)floor((cmx + cmn) / 2.0);

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max({ans, abs(m1 - a[i].first), abs(m2 - a[i].second)});
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    solve();
    return 0;
}
