// Author: Saikat_deb | Created: 2025-08-05 20:52
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using Oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
    cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__        \
         << "):",                                                              \
        dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pp;
typedef vector<vi> vvi;
typedef vector<LL> vl;
typedef vector<pair<int, int>> vp;

#define itr(i, n) for (int i = 0; i < (int)n; i++)
#define itr_n(i, n) for (int i = 1; i <= n; i++)
#define itr_r(i, n) for (int i = n - 1; i >= 0; i--)
#define RESET(a, b) memset(a, b, sizeof(a))
#define inf_p INT_MAX
#define inf_n INT_MIN
#define inf_pll LONG_LONG_MAX
#define inf_nll LONG_LONG_MIN
#define read(a)                                                                \
    for (auto &i : a)                                                          \
        cin >> i;
#define write(a)                                                               \
    for (auto &i : a)                                                          \
        cout << i << " ";                                                      \
    cout << "\n";
#define write_pair(a)                                                          \
    for (auto T : a)                                                           \
        cout << T.first << " " << T.second << "\n";
#define IOS()                                                                  \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);
#define MOD 1000000007
#define MOD1 998244353
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1},
          d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

LL inverse(LL i) {
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}
bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    map<int, int> freq;

    itr(i, n) {
        cin >> a[i];
        freq[a[i]]++;
    }
    if (freq.size() > 2) {
        cout << "No\n";
        return;
    }
    if (freq.size() == 1) {
        cout << "Yes\n";
        return;
    }

    map<int, int>::iterator it;
    it = freq.begin();
    auto f = it;
    it++;
    auto s = it;
    if (n & 1) {
        if (abs(f->second - s->second) != 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    } else {
        if (f->second != s->second)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}

int main() {
    IOS();
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
// freopen("output.txt","w", stdout);
#endif
    cout << fixed << setprecision(9);
    int test = 1;
    cin >> test;
    itr(each, test) { solve(); }
    return 0;
}
