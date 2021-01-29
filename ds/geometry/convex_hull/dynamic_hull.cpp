/**
 * Description: Given a set of pairs (a, b), finding optimal ax + b in O(logn)
 */

bool Q;

using tp = int;

struct Line {
  mutable tp k, m, p; // slope, y-intercept, last optimal x
  bool operator< (const Line& o) const {
    return Q? p < o.p: k < o.k;
  }
};

struct DynamicHull : multiset<Line> {
  const bool ismin; // ismin is true if we want the minimum value, false otherwise
  DynamicHull(bool c = 0) : ismin(c) {}
  const tp inf = numeric_limits<tp>::max();

  tp div(tp a, tp b) {
    if (b < 0) a *= -1, b *= -1;
    if (a >= 0) return a / b;
    return -((-a + b - 1) / b);
  }

  bool isect(iterator x, iterator y) {
    // updates x->p, and determines if y is not needed
    if (y == end()) {
      x->p = inf;
      return false;
    }
    if (x->k == y->k) {
      x->p = (x->m > y->m)? inf: -inf;
    } else {
      x->p = div(y->m - x->m, x->k - y->k);
    }
    return x->p >= y->p;
  }

  void add(tp k, tp m) {
    if (ismin) {
      k *= -1;
      m *= -1;
    }
    auto z = insert({k, m, (tp)0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }

  tp query(tp x) {
    assert(!empty());
    Q = 1;
    auto it = lower_bound({0, 0, x});
    Q = 0;
    return (it->k * x + it->m) * (ismin? -1: 1);
  }
};
