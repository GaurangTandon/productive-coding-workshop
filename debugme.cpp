#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<v> vv;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
const ll MOD = 1e9 + 7;
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo \
    { no return; }
#define round(x, y) ((2 * x + y) / (2 * y))
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define sq(x) ((x) * (x))

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template<typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
    vector<T> a = vector<T>(n + oneIndexed);

    for (ll i = 0; i < n; i++) {
        T p;
        cin >> p;
        a[i + oneIndexed] = p;
    }

    return move(a);
}

template<typename T, typename A>
void pa(vector<T, A>
        const &a,
        ll begin = 0, ll
        end = -1
) {
    if (end == -1)
        end = sz(a) - 1;
    for (
            ll i = begin;
            i <=
            end;
            i++) {
        cout << a[i] << " ";
    }
    cout <<
         endl;
}

v colors;
v ans(2e5 + 1, -1);

void dfs(vv &adjList, ll curr, ll prev = -1) {
    ll best_ans = colors[curr] ? 1 : -1;

    for (auto neigh : adjList[curr]) {
        if (neigh != prev) {
            dfs(adjList, neigh, curr);

            best_ans += max(0ll, ans[neigh]);
        }
    }

    amax(ans[curr], best_ans);
}

void dfs2(vv &adjList, ll curr, ll prev = -1, ll propagated = 0) {
    amax(ans[curr], propagated + ans[curr]);

    ll sum = ans[curr];
    for (auto neigh : adjList[curr]) {
        if (neigh == prev)continue;

        ll redo = 0;

        if (ans[neigh] > 0) {
            redo = ans[neigh];
        }

        sum -= redo;

        dfs2(adjList, neigh, curr, sum);

        sum += redo;
    }
}

void solve() {
    ll n;
    cin >> n;
    colors = ga(n, 1);

    vv adjList(n);
    for (ll i = 0; i < n - 1; i++) {
        ll x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(adjList, 1);
    dfs2(adjList, 1);
    pa(ans, 1, n);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen("file", "r", stdin);
    // freopen("file", "w", stdout);
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}