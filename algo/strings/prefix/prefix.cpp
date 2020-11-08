vector<int> prefix_function (const string& s) {
  int n = (int) s.length();
  vector<int> prefix(n, 0);
  for (int i = 1; i < n; i++) {
    int j = prefix[i - 1];
    while (j > 0 && s[i] != s[j]) j = prefix[j - 1];
    if (s[i] == s[j]) j++;
    prefix[i] = j;
  }
  return prefix;
}