#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

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

signed main () {
  return 0;
}