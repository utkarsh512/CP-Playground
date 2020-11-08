#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int spf[N];

void sieve() {
  int n = N - 1;
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

signed main () {
  return 0;
}