#include <bits/stdc++.h>
using namespace std;

/**
 * Divisor count and sum for 1 .. n in O(nlgn)
 */

const int N = 1e5 + 10;

vector<int> divcount(N, 0);
vector<int> divsum(N, 0);

void sieve() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      ++divcount[j];
      divsum[j] += i;
    }
  }
}

signed main() {
  return 0;
}