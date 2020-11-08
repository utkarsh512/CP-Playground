#include <bits/stdc++.h>
using namespace std;

void normalize (vector<int>& a) {
  int n = (int)a.size();
  int idx = 0;
  map<int, int> foo;
  for (int i = 0; i < n; i++) {
    if (foo.find(a[i]) == foo.end()) foo[a[i]] = idx++;
  }
  for (int i = 0; i < n; i++) a[i] = foo[a[i]];
}

int main() {
  return 0;
}