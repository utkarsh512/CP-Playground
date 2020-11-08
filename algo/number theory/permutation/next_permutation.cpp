#include <bits/stdc++.h>
using namespace std;

const int infi = 2e9;

/**
 * Description : Transforms a permutation to its next lexicographical permutation
 * Complexity  : O(NlogN)
 * Verification: Self
 */

void next_shuffle (vector<int>& a) {
  int n = (int)a.size();
  int idx = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[idx]) idx--;
    else break;
  }
  if (idx == 0) {
    return;
  }
  int x = a[idx - 1];
  int pos, nin = infi;
  for (int i = n - 1; i >= idx; i--) {
    if (a[i] > x && a[i] < nin) {
      pos = i;
      nin = a[i];
    }
  }
  swap(a[idx - 1], a[pos]);
  sort(a.begin() + idx, a.end());
}