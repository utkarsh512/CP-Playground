#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

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

signed main() {
  return 0;
}