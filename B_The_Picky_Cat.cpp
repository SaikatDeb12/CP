// Author: Saikat_deb | Created: 2025-05-20 10:50
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

// C:\msys64\mingw64\include\c++\11.2.0\ext\pb_ds\detail\resize_policy
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// less, greater or less_equal
// fn: find_by_order(index), order_of_key(element)-> all the elements that are less than element , lower and upper_bound, erase
template <typename T>
using Oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*neal's debug code: */
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifndef ONLINE_JUDGE
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
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
#define read(a)       \
    for (auto &i : a) \
        cin >> i;
#define write(a)          \
    for (auto &i : a)     \
        cout << i << " "; \
    cout << "\n";
#define write_pair(a) \
    for (auto T : a)  \
        cout << T.first << " " << T.second << "\n";
#define IOS()                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1000000007
#define MOD1 998244353
const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

LL inverse(LL i)
{
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * inverse(MOD % i)) % MOD + MOD) % MOD;
}

bool isPrime(int n)
{
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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    itr(i, n)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    int first = a[0];
    sort(a.begin(), a.end());
    int m = int(floor(n / 2) + 1);
    itr(i, m)
    {
        if (a[i] == first)
        {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
    // int n;
    // cin >> n;
    // vi a(n);
    // read(a);
    // int first = a[0];
    // sort(a.begin(), a.end());
    // dbg(a);

    // int mid = (n - 1) / 2;
    // if (a[mid] == first)
    // {
    //     cout << "YES\n";
    //     return;
    // }

    // int index = 0;
    // itr(i, n)
    // {
    //     if (a[i] == first)
    //     {
    //         index = i;
    //         break;
    //     }
    // }

    // int steps = abs(index - mid);
    // int cnt = 0;
    // if (index > mid)
    // {
    //     itr(i, index)
    //     {
    //         if (abs(a[i]) > abs(first))
    //             cnt++;
    //     }
    // }
    // else
    // {
    //     for (int i = index; i < n; i++)
    //     {
    //         if (abs(a[i]) > abs(first))
    //             cnt++;
    //     }
    // }
    // if (cnt >= steps)
    // {
    //     cout << "YES\n";
    //     return;
    // }

    // first *= -1;
    // itr(i, n)
    //     a[i] *= -1;
    // sort(a.begin(), a.end());
    // dbg(a);

    // mid = (n - 1) / 2;
    // if (a[mid] == first)
    // {
    //     cout << "YES\n";
    //     return;
    // }

    // index = 0;
    // itr(i, n)
    // {
    //     if (a[i] == first)
    //     {
    //         index = i;
    //         break;
    //     }
    // }
    // dbg(index);
    // steps = abs(index - mid);
    // cnt = 0;
    // if (index > mid)
    // {
    //     itr(i, index)
    //     {
    //         if (abs(a[i]) > abs(first))
    //             cnt++;
    //     }
    // }
    // else
    // {
    //     for (int i = index; i < n; i++)
    //     {
    //         if (abs(a[i]) > abs(first))
    //             cnt++;
    //     }
    // }
    // if (cnt >= steps)
    // {
    //     cout << "YES\n";
    //     return;
    // }

    // cout << "NO\n";
}

int main()
{
    IOS();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
// freopen("output.txt","w", stdout);
#endif
    cout << fixed << setprecision(9);
    int test = 1;
    cin >> test;
    // START
    itr(each, test)
    {
        solve();
    }
    // END
    return 0;
}