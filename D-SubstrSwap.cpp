// Author: Saikat_deb | Created: 2025-08-31 17:33
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using Oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifndef ONLINE_JUDGE
static ofstream debug_stream("error.txt");
#endif

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

void dbg_out() {
#ifndef ONLINE_JUDGE
    debug_stream << endl;
#endif
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
#ifndef ONLINE_JUDGE
    debug_stream << ' ' << H;
    dbg_out(T...);
#endif
}

#ifndef ONLINE_JUDGE
#define dbg(...)                                                               \
    debug_stream << '[' << __FILE__ << ':' << __LINE__ << "] ("                \
                 << #__VA_ARGS__ << "):",                                      \
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
#define inf_pll LLONG_MAX
#define inf_nll LLONG_MIN
#define read(a)                                                                \
    for (auto &i : a)                                                          \
    cin >> i
#define write(a)                                                               \
    for (auto &i : a)                                                          \
        cout << i << " ";                                                      \
    cout << "\n"
#define write_pair(a)                                                          \
    for (auto T : a)                                                           \
    cout << T.first << " " << T.second << "\n"
#define IOS()                                                                  \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)
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
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

struct Node {
    bool swapFlag;
    Node() : swapFlag(false) {}
};

struct SegmentTree {
    int n;
    vector<Node> tree;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n);
    }

    void apply(int idx) { tree[idx].swapFlag = !tree[idx].swapFlag; }

    void pushDown(int idx) {
        if (tree[idx].swapFlag) {
            apply(idx * 2);
            apply(idx * 2 + 1);
            tree[idx].swapFlag = false;
        }
    }

    void update(int idx, int L, int R, int l, int r) {
        if (r < L || R < l)
            return;
        if (l <= L && R <= r) {
            apply(idx);
            return;
        }
        pushDown(idx);
        int mid = (L + R) / 2;
        update(idx * 2, L, mid, l, r);
        update(idx * 2 + 1, mid + 1, R, l, r);
    }

    bool query(int idx, int L, int R, int pos) {
        if (L == R) {
            return tree[idx].swapFlag;
        }
        pushDown(idx);
        int mid = (L + R) / 2;
        if (pos <= mid)
            return query(idx * 2, L, mid, pos);
        else
            return query(idx * 2 + 1, mid + 1, R, pos);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    SegmentTree st(n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        st.update(1, 0, n - 1, l, r);
    }

    itr(i, n) {
        bool flag = st.query(1, 0, n - 1, i);
        if (flag)
            cout << b[i];
        else
            cout << a[i];
    }
    cout << "\n";
}

int main() {
    IOS();
    cout << fixed << setprecision(9);
    int test = 1;
    // cin >> test;
    itr(each, test) solve();
    return 0;
}
