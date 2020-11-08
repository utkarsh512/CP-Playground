#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
void debug_out() { cerr << "\n"; }
template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define trace(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 0; i < n; i++) cerr << a[i] << ", "; cerr << "]\n"
#else
#define debug(...) 42
#define trace(a, n) 42
#endif
#define int long long
#define double long double
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define uint unsigned int
#define pi pair<int, int>
const long long infi = 2e9;
const long long infl = 4e18;
const long long md = 998244353;
const double PI = 3.14159265358979323846;
template <typename Map>bool map_compare (Map const &lhs, Map const &rhs) { return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());}
template <class T, class Cmp = less<T>> using oset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
inline long long modpow(long long x, long long n) { long long res = 1; while (n > 0) { if (n % 2) res = (res * x) % md; x = (x * x) % md; n /= 2; } return res; }
inline long long inv(long long x) {return modpow(x, md-2);}
inline long long log_2 (long long n) { return (n > 1ll)? 1ll + log_2(n/2): 0ll;}
inline long long log_10 (long long n) { return (n > 1ll)? 1ll + log_10(n/10): 0ll;}
inline void add(long long& a, long long b) {a = ((a % md) + (b % md)) % md;}
inline void sub(long long& a, long long b) {a = ((a % md) - (b % md) + md) % md;}
inline void mul(long long& a, long long b) {a = ((a % md) * (b % md)) % md;}
inline long long gcd(long long a, long long b) { long long r; while (b) { r = a % b; a = b; b = r;} return a; }
inline long long randint (long long limit = md) { uniform_int_distribution<long long> dis(0, limit); return dis(rng); }
inline double random (double limit = (double)md) { uniform_real_distribution<double> dis((double)0, limit); return dis(rng); }

template <class T>
struct cmp {
  bool operator() (const T& x, const T& y) const {
    return x > y;
  }
  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef bool result_type;
};

/**
 * The following program does the following:
 *  Given an binary array A of length n, we can change atmost K zeroes to ones
 *  determine the maximum length subsegment achievable
 * 
 *  Infact, this concept can be used in lots of problem
 * 
 * Time Complexity is O(nlogn) -> best possible
 */

signed main() {
#ifdef READ_FILE
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(10);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), dp(n+1, 0), ones;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) ones.pb(i);
  }
  for (int i = n-1; i >= 0; i--) {
    dp[n-i] = dp[n-i-1] + (a[i] == 0);
  }
  dp.erase(dp.begin());
  debug(dp);
  int mx = 0, idx = -1, rm = 0;
  ones.pb(n);
  for (int i = 0; i < n; i++) {
    int foo = dp[n-1-i];
    auto it = upper_bound(all(dp), foo + k);
    int bar;
    if (it == dp.end()) {
      bar = sz(dp) - 1;
    } else {
      bar = it - dp.begin();
      bar = max(0ll, bar-1);
    }
    debug(bar);
    int rem = foo + k - dp[bar] - !a[i];
    debug(rem);
    bar = n-1-bar;
    auto ex = *upper_bound(all(ones), i);
    int cand = i - bar + 1 + min(rem, ex-i-1);
    debug(i, a[i], cand);
    if (cand > mx) {
      mx = cand;
      idx = i;
      rm = rem;
    }
  }
  debug(mx, idx);
  int tp = k-rm;
  for (int i = idx+1; i < n && rm > 0; i++) {
    if (a[i]) continue;
    a[i] = 1; rm--;
  }
  for (int i = idx; i >= 0 && tp > 0; i--) {
    if (a[i]) continue;
    a[i] = 1; tp--;
  }
  cout << mx << "\n";
  for (auto x : a) cout << x << " ";
  cout << "\n";
  return 0;
}