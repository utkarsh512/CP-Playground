#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int spf[N+1];  // spf[i] contains smallest prime factor of i

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

vector<int> _prime_f (int x) {
  vector<int> r;
  while (x != 1) {
    r.push_back(spf[x]);
    x /= spf[x];
  }
  return r;
}

signed main () {
  return 0;
}