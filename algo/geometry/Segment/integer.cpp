/**
 * Description: Handling segments in 2D (integer cases)
 */

long long sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  return max(a, c) <= min(b, d);
}

struct Seg {
  Point<long long> P, Q;
  Seg() {}
  Seg(const Point<long long>& P_, const Point<long long>& Q_) : P(P_), Q(Q_) {}
  Seg(long long A, long long B, long long C, long long D) {
    P = Point<long long>(A, B);
    Q = Point<long long>(C, D);
  }
  bool isect(const Seg& oth) {
    if (oth.P.cross(P, oth.Q) == 0 && oth.P.cross(Q, oth.Q) == 0) {
      return inter1(P.x, Q.x, oth.P.x, oth.Q.x) && inter1(P.y, Q.y, oth.P.y, oth.Q.y);
    }
    return sgn(P.cross(Q, oth.P) != sgn(P.cross(Q, oth.Q)) && sgn(oth.P.cross(oth.Q, P) != sgn(oth.P.cross(oth.Q, Q))));
  }
};
