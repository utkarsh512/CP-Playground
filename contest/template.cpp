#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL
string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N> string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <class A, class B> string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <class A, class B, class C> string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <class A, class B, class C, class D> string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
template <class A> string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <class Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << to_string(arg1) << "\n";
}
template <class Arg1, class... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << to_string(arg1) <<" | ";
  __f(comma+1, args...);
}
#else
#define debug(...) 69
#endif

#define int long long
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define pi pair<int, int>

template <class L, class R> istream& operator>> (istream& is, pair<L, R>& P) { return is >> P.ff >> P.ss; }
template <class T> istream& operator>> (istream& is, vector<T>& V) { for (auto& e : V) is >> e; return is; }
template <class L, class R> ostream& operator<< (ostream& os, pair<L, R>& P) { return os << P.ff << " " << P.ss; }
template <class T> ostream& operator<< (ostream& os, vector<T>& V) { for (auto& e : V) os << e << " "; return os; }
template <class T> void remove_dups (vector<T>& V) { V.erase(unique(V.begin(), V.end()), V.end()); }

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
inline long long gcd(long long a, long long b) { long long r; while (b) { r = a % b; a = b; b = r;} return a; }
inline long long ceil_div(long long a, long long b) { return a / b + ((a ^ b) > 0 && a % b != 0); }
inline long long rnd (long long l, long long r) { uniform_int_distribution<long long> dis(l, r); return dis(rng); }

const int infi = 2e9;
const long long infl = 4e18;
const int md = 998244353;
const double PI = 3.14159265358979323846;
const double eps = 1e-8;

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
  freopen("input.txt", "r", stdin);
#endif
#ifdef CHK_RNDM
  freopen("output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  return 0;
}
