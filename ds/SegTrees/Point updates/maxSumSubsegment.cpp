

/**
 * Implementation of Segment Tree to answer the query:
 *  Given (l, r), find (l', r') [l' >= l && r' <= r] such that sum a[l'] + ... + a[r'] is maximum possible
 */

struct node {
  int sum, pref, suff, ans;
};

const int N = 3e5 + 100;

int a[N];
node t[4*N];

node newNode (int val) {
  node p;
  p.sum = val;
  p.pref = p.suff = p.ans = max(0ll, val);
  return p;
}

node combine (node l, node r) {
  node p;
  p.sum = l.sum + r.sum;
  p.pref = max(l.pref, l.sum + r.pref);
  p.suff = max(r.suff, l.suff + r.sum);
  p.ans = max(max(l.ans, r.ans), l.suff + r.pref);
  return p;
}

void build (int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = newNode(a[tl]);
  } else {
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    t[v] = combine(t[2*v], t[2*v+1]);
  }
}

void update (int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = newNode(val);
  } else {
    int tm = (tl + tr) / 2;
    if (pos <= tm) update(2*v, tl, tm, pos, val);
    else update(2*v+1, tm+1, tr, pos, val);
    t[v] = combine(t[2*v], t[2*v+1]);
  }
}

node query (int v, int tl, int tr, int l, int r) {
  if (l > r) return newNode(0);
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return combine(query(2*v, tl, tm, l, min(r, tm)), query(2*v+1, tm+1, tr, max(l, tm+1), r));
}
