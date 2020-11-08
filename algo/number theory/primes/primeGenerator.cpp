#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10; // Max limit of the range
vector<int> primes; // contains prime numbers upto max limit
vector<bool> isprime(N+1, true); // isprime[x] = true if x is prime

void _p_sieve() {
  int n = N;
  for (int p = 2; p*p <= n; ++p) {
    if (isprime[p]) for (int i = p*p; i <= n; i += p) isprime[i] = false;
  }
  for (int p = 2; p <= n; ++p) if (isprime[p]) primes.push_back(p);
}

pair<int, int> _floor_prime (int x) {
  /**
   * Returns the index and prime itself less than or equal to x (closest)
   */
  pair<int, int> ans = {-1, -1};
  int lo = 0, hi = (int)primes.size() - 1;
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

pair<int, int> _ceil_prime (int x) {
  /**
   * Returns the index and primes itself greater than or equal to x (closest)
   */
  pair<int, int> ans = {-1, -1};
  int lo = 0, hi = (int)primes.size() - 1;
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

signed main() {
  return 0;
}