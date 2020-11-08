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

/* For finding fibonacci-like sequences in logarithmic time 

Here, we only need to modify matrix X,
matrix F is the 3x3 relation bw present state and previous state.

For e.g. fibonacci seq follow: f(n) = f(n-1) + f(n-2)
We can write,
| f(n)   |     | 1    1    0 |   | f(n-1) |
| f(n-1) |  =  | 1    0    0 |   | f(n-2) |
| f(n-2) |     | 0    1    0 |   | f(n-3) |

We have,
  F = (X**k) (I)

  where F is the final state, I is the initial state, X is the transitioning matrix

*/

ll I[3] = {0ll, 1ll, 1ll}; // the initial state f(0) = I[0], f(1) = I[1], f(2) = I[2]
ll X[3][3] = {{1ll, 1ll, 0ll}, {1ll, 0ll, 0ll}, {0ll, 1ll, 0ll}}; // the transitioning matrix


void multiply (ll a[3][3], ll b[3][3]) {
  ll mul[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mul[i][j] = 0;
      for (int k = 0; k < 3; k++) {
        mul[i][j] += (a[i][k] * b[k][j]) % MOD;
      }
      mul[i][j] %= MOD;
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[i][j] = mul[i][j];
    }
  }
}
 
ll power(ll F[3][3], ll n) {
  if (n == 1) return ((I[2] * F[0][0]) % MOD + (I[1] * F[0][1]) % MOD + (I[0] * F[0][2]) % MOD) % MOD;
  power(F, n / 2);
  multiply(F, F);
  if (n % 2) multiply(F, X);
  return ((I[2] * F[0][0]) % MOD + (I[1] * F[0][1]) % MOD + (I[0] * F[0][2]) % MOD) % MOD;
}
 
ll findN(ll n) {
  /**
   * Return nth term of sequence (0-indexed)
   */
  ll F[3][3];
  for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) F[i][j] = X[i][j];
  if (n == 0) return I[0];
  if (n == 1) return I[1];
  if (n == 2) return I[2];
  return power(F, n - 2);
}

const int MAXN = 101;
ll _f[MAXN];

int cfn (ll n) {
  /**
   * Returns the index of closest fibonacci number less than or equal to n
   */
  _f[0] = 1ll;
  _f[1] = 2ll;
  int i;
  for (i = 2; _f[i-1] <= n; i++) {
    _f[i] = _f[i-1] + _f[i-2];
  }
  return (i-2);
}

string fibcode(ll n) {
  int index = cfn(n);
  string s = string(index+2, ' ');
  int i = index;
  while (n) {
    s[i] = '1';
    n -= _f[i];
    --i;
    while (i >= 0 && _f[i] > n) {
      s[i] = '0';
      --i;
    }
  }
  s[index + 1] = '1';
  return s;
}

signed main() {
  return 0;
}