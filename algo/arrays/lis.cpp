#include <bits/stdc++.h>
using namespace std;

template <class T>
int LIS (T arr[], int n) {
  int dp[n];
  dp[0] = 1;
  for (int i = 1; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
  }
  return *max_element(dp, dp+n);
}