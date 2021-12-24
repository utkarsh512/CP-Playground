#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;

// =========================== random ==================================

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

inline long long rnd(long long l, long long r) { 
  uniform_int_distribution<long long> dis(l, r); 
  return dis(rng); 
}

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
 
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }

  template<typename L, typename R>
  size_t operator()(pair<L,R> const& Y) const{
      static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(Y.first * 31ull + Y.second + FIXED_RANDOM);
  }
};

// ============================= containers ===================================

template <class key, class val>
using hash_map = unordered_map<key, val, custom_hash>;

template <class T>
using hash_set = unordered_set<T, custom_hash>;

template <class T, class cmp = less<T>>
using ordered_set = tree<T, null_type, cmp, rb_tree_tag,tree_order_statistics_node_update>;

template <class key, class value, class cmp = less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
using max_heap = priority_queue<T>;

template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

// ============================== debug =======================================

string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N> string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <class A, class B> string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <class A, class B, class C> string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <class A, class B, class C, class D> string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
template <class A> string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}

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

#ifdef LOCAL
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 69
#endif

template <class T, const int SZ>
void debug(T v[SZ], int n) {
  for (int i = 0; i < n; i++) {
    cout << v[i] << "\t";
  }
  cout << "\n";
}

template <class T, const int SZ>
void debug(T v[][SZ], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << v[i][j] << "\t";
    }
    cout << "\n";
  }
}

#ifdef __SIZEOF_INT128__
ostream& operator << (ostream &os, __int128 const& value){
  static char buffer[64];
  int index = 0;
  __uint128_t T = (value < 0) ? (-(value + 1)) + __uint128_t(1) : value;
  if (value < 0) 
    os << '-';
  else if (T == 0)
    return os << '0';
  for(; T > 0; ++index){
    buffer[index] = static_cast<char>('0' + (T % 10));
    T /= 10;
  }    
  while(index > 0)
    os << buffer[--index];
  return os;
}
istream& operator >> (istream& is, __int128& T){
  static char buffer[64];
  is >> buffer;
  size_t len = strlen(buffer), index = 0;
  T = 0; int mul = 1;
  if (buffer[index] == '-')
    ++index, mul *= -1;
  for(; index < len; ++index)
    T = T * 10 + static_cast<int>(buffer[index] - '0');
  T *= mul;    
  return is;
}
#endif

// ========================== code starts ===============================

void solve() {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
