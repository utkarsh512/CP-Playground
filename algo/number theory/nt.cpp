#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define len(x) (int)x.length()
#define ac(x, i) get<i>(x)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll ,ll>
#define pli pair<ll, int>
#define ff first
#define ss second
#define trace(x)    cerr << #x << ": " << x << "\n"
#define trav0(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 0; i < n; i++) cerr << a[i] << ", "; cerr << "]\n"
#define trav1(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 1; i <= n; i++) cerr << a[i] << ", "; cerr << "]\n"
#define trap0(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 0; i < n; i++) cerr << "(" << a[i].ff << ", " << a[i].ss << "), "; cerr << "]\n"
#define trap1(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 1; i <= n; i++) cerr << "(" << a[i].ff << ", " << a[i].ss << "), "; cerr << "]\n"
#define travMap(a)  cerr << #a << "[" << sz(a) <<  "] = ["; for (auto i : a) cerr << "(" << i.ff << ", " << i.ss << "), "; cerr << "]\n"
#define traverse(a) cerr << #a << "[" << sz(a) <<  "] = ["; for (auto i : a) cerr << i << ", "; cerr << "]\n"
#define random_permute(x) shuffle(all(x), mt)
typedef unsigned int uint;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<pll> vll;
const int infi = 1e9;
const ll infl = 1e18;
const int MOD = 1e9 + 7;
template <typename Map> bool map_compare (Map const &lhs, Map const &rhs) { return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());}
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
int randint(int p = MOD) { return mt() % p;}
ll randlong(ll p = infl) { return mt() % p;}
ll log_2 (ll n) { return (n > 1ll)? 1ll + log_2(n/2): 0ll;}
inline void add(ll&a, ll b) {a += b; if (a >= MOD) a -= MOD;}
inline void sub(ll&a, ll b) {a -= b; if (a < 0) a += MOD;}

/* BASIC FUNCTIONS */

ll binpow(ll x, ll n) { // x^n
  int result = 1;
  while(n > 0) {
    if(n % 2 == 1) result=result * x;
    x = x * x;
    n = n / 2;
  }
  return result;
}

ll modpow(ll x, ll n, ll m = ll(MOD)) { // (x^n) % MOD
  int result = 1;
  while(n > 0) {
    if(n % 2 == 1) result = (result * x) % m;
    x = (x * x) % m;
    n = n / 2;
  }
  return result;
}

ll modinv (ll x) {  // (1/x) % MOD
  return modpow(x, MOD-2);
}

pll extendedEuclid (ll a, ll b, pll p = {1, 0}) { 
  // Solves eqn ax + by = gcd(a, b), return (x, y)
  if (b == 0) return p;
  pll q = extendedEuclid(b, a%b);
  ll temp = q.ff;
  q.ff = q.ss;
  q.ss = temp - (a/b)*q.ss;
  return q;
}

/* Probabilistic primality tests */

bool _isprime_fermat (int n, int it = 5) {
  if (n < 4) return (n == 2 || n == 3);
  for (int i = 0; i < it; i++) {
    int a = 2 + mt() % (n - 3);
    if (modpow(ll(a), ll(n-1), ll(n)) != 1ll) return false;
  }
  return true;
}

/* Primes and sieves */

const int N = 1e6 + 10; // Max limit of the range
vl primes; // contains prime numbers upto max limit
vector<bool> isprime(N+1, true); // isprime[x] = true if x is prime

void _p_sieve() {
  int n = N;
  for (int p = 2; p*p <= n; ++p) {
    if (isprime[p]) for (int i = p*p; i <= n; i += p) isprime[i] = false;
  }
  for (int p = 2; p <= n; ++p) if (isprime[p]) primes.pb(p);
}

pii _floor_prime (int x) {
  /**
   * Returns the index and prime itself less than or equal to x (closest)
   */
  pii ans = {-1, -1};
  int lo = 0, hi = sz(primes) - 1;
  int mid = lo + (hi - lo) / 2;
  while (lo <= hi) {
    if (x == primes[mid]) {
      ans = {mid, x};
      return ans;
    }
    if (x > primes[mid]) {
      ans = {mid, primes[mid]};
      lo = mid + 1;
    } else hi = mid - 1;
    mid = lo + (hi - lo) / 2;
  }
  return ans;
}

pii _ceil_prime (int x) {
  /**
   * Returns the index and primes itself greater than or equal to x (closest)
   */
  pii ans = {-1, -1};
  int lo = 0, hi = sz(primes) - 1;
  int mid = lo + (hi - lo) / 2;
  while (lo <= hi) {
    if (x == primes[mid]) {
      ans = {mid, x};
      return ans;
    }
    if (x > primes[mid]) lo = mid + 1;
    else {
      ans = {mid, primes[mid]};
      hi = mid - 1;
    }
    mid = lo + (hi - lo) / 2;
  }
  return ans;
}

/* Smallest prime factor, Largest prime factor and Maximum divisor */

int spf[N+1];
void _spf_sieve() {
  int n = N;
  for (int i = 0; i <= n; i++) spf[i] = 0;
  spf[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (spf[i] == 0) {
      spf[i] = i;
      for (int j = 2*i; j <= n; j += i) {
        if (spf[j] == 0) spf[j] = i;
      }
    }
  }
}

vi _prime_f (int x) {
  /* Prime factorization in log(x) time complexity */
  vi r;
  while (x != 1) {
    r.pb(spf[x]);
    x /= spf[x];
  }
  return r;
}

int lpf[N+1];
void _lpf_sieve() {
  int n = N;
  for (int i = 0; i <= n; i++) lpf[i] = 0;
  lpf[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (lpf[i] == 0) {
      lpf[i] = i;
      for (int j = 2*i; j <= n; j += i) lpf[j] = i;
    }
  }
}

int md[N+1];
void _md_sieve() {
  int n = N;
  for (int i = 0; i <= n; i++) md[i] = 0;
  md[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (md[i]) continue;
    for (int j = i; j <= n; j += i) {
      if (md[j]) continue;
      md[j] = j / i;
    }
  }
}

signed main() {
  return 0;
}