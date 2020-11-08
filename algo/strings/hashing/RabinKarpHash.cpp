const int p = 67;
const int maxn = 1e5 + 10;
long long rdx[maxn], rdxi[maxn];

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
};
template <class key, class val>
using hash_table = gp_hash_table<key, val, custom_hash>;

hash_table<char, int> M;

void pre() {
  int i = 1;
  for (char j = '0'; j <= '9'; j++) M[j] = i++;
  for (char j = 'A'; j <= 'Z'; j++) M[j] = i++;
  for (char j = 'a'; j <= 'z'; j++) M[j] = i++;

  rdx[0] = 1;
  rdxi[0] = inv(rdx[0]);
  for (int i = 1; i < maxn; i++) {
    rdx[i] = rdx[i - 1] * p % md;
    rdxi[i] = inv(rdx[i]);
  }
}

struct StringHasher {
  string s;
  int length;
  vector<long long> pref, suf;

  void fillprefHash() {
    long long h = 0;
    for (int i = 0; i < length; i++) {
      h = (h + (M[s[i]]) * rdx[i]) % md;
      pref[i] = h;
    }
  }

  void fillsufHash() {
    long long h = 0;
    for (int i = 0; i < length; i++) {
      h = (h + (M[s[length - 1 - i]]) * rdx[i]) % md;
      suf[i] = h;
    }
  }

  StringHasher(const string& _s) : s(_s){
    length = sz(s);
    pref.assign(length, 0);
    suf.assign(length, 0);
    fillprefHash();
    fillsufHash();
  }

  long long fwd (int i, int j) {
    long long left = (i != 0)? pref[i - 1]: 0;
    long long right = pref[j];
    long long h = right - left;
    if (h < 0) h += md;
    return (h * rdxi[i] % md);
  }

  long long bwd (int i, int j) {
    swap(i, j);
    i = length - 1 - i;
    j = length - 1 - j;
    long long left = (i != 0)? suf[i - 1]: 0;
    long long right = suf[j];
    long long h = right - left;
    if (h < 0) h += md;
    return (h * rdxi[i] % md);
  }
};