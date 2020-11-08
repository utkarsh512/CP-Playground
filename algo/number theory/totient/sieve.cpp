#include <bits/stdc++.h>
using namespace std;

#define int long long

/**
 * Evaluates totient function of 1 .. n in O(nlglgn)
 */

vector<int> sieve (int n) {
  vector<int> phi(n+1);
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) if (phi[i] == i) {
    for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
  }
  return phi;
}