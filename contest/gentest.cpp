#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ld = long double;

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
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define uint unsigned int
#define pi pair<int, int>
#define pl pair<ll, ll>

template <class L, class R> istream& operator>> (istream& is, pair<L, R>& P) { return is >> P.ff >> P.ss; }
template <class T> istream& operator>> (istream& is, vector<T>& V) { for (auto& e : V) is >> e; return is; }
template <class L, class R> ostream& operator<< (ostream& os, pair<L, R>& P) { return os << P.ff << " " << P.ss; }
template <class T> ostream& operator<< (ostream& os, vector<T>& V) { for (auto& e : V) os << e << " "; return os; }
template <class T = int> int bsl(vector<T> a, T x) { int lo = 0; int hi = sz(a) - 1; int req = -1; int mid = lo + (hi - lo) / 2; while (lo <= hi) { if (a[mid] <= x) { req = mid; lo = mid + 1; } else { hi = mid - 1; } mid = lo + (hi - lo) / 2; } return req; }
template <class T = int> int bsg(vector<T> a, T x) { int lo = 0; int hi = sz(a) - 1; int req = -1; int mid = lo + (hi - lo) / 2; while (lo <= hi) { if (a[mid] >= x) { req = mid; hi = mid - 1; } else { lo = mid + 1; } mid = lo + (hi - lo) / 2; } return req; }

template <typename Map>bool map_compare (Map const &lhs, Map const &rhs) { return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());}
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
inline long long randint (long long l, long long r) { uniform_int_distribution<long long> dis(l, r); return dis(rng); }
inline double random (double l, double r) { uniform_real_distribution<double> dis(l, r); return dis(rng); }
inline double randn() { normal_distribution<double> dis; return dis(rng); }
inline double rdn (double std_dev, double mean) { return std_dev * randn() + mean; }

const int infi = 2e9;
const long long infl = 4e18;
const int md = 998244353;
const double PI = 3.14159265358979323846;

inline long long modpow(long long x, long long n) { long long res = 1; while (n > 0) { if (n % 2) res = (res * x) % md; x = (x * x) % md; n /= 2; } return res; }
inline long long inv(long long x) {return modpow(x, md-2);}
inline bool imax (long long& a, long long b) { bool res = (b > a); a = max(a, b); return res;}
inline bool emax (long long& a, long long b) { bool res = (b >= a); a = max(a, b); return res;}
inline bool imin (long long& a, long long b) { bool res = (b < a); a = min(a, b); return res;}
inline bool emin (long long& a, long long b) { bool res = (b <= a); a = min(a, b); return res;}
inline long long log_2 (long long n) { return (n > 1ll)? 1ll + log_2(n/2): 0ll;}
inline long long log_10 (long long n) { return (n > 9ll)? 1ll + log_10(n/10): 0ll;}
inline void add(long long& a, long long b) {a = ((a % md) + (b % md)) % md;}
inline void sub(long long& a, long long b) {a = ((a % md) - (b % md) + md) % md;}
inline void mul(long long& a, long long b) {a = ((a % md) * (b % md)) % md;}
inline long long gcd(long long a, long long b) { long long r; while (b) { r = a % b; a = b; b = r;} return a; }

template <class T>
struct cmp {
  bool operator() (const T& x, const T& y) const {
    return x > y;
  }
  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef bool result_type;
};

signed main() {
#ifdef READ_FILE
  freopen("input.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int tt = 10;
  cout << tt << "\n";
  while (tt--) {
    int n = randint(1, 50);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
      int r = randint(1, 50);
      cout << r << " ";
    }
    cout << "\n";
  }
  return 0;
}