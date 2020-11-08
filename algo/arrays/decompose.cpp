/**
 * Check if the given array A can be decomposed into an increasing
 * array I and decreasing array D such that
 * 
 * I[i] + D[i] = A[i] for all i
 * 
 * Complexity: O(n)
 */

bool decomp(vector<int> a) {
  int lol = 0;
  for (int i = 1; i < n; i++) {
    lol += max(0ll, a[i] - a[i - 1]);
    if (lol > a[i]) {
      return false;
    }
  }
  return true;
}