#include <bits/stdc++.h>
using namespace std;
#define double long double

double overlappingArea (double r1, double r2, double dist) {
  /**
   * Returns area of intersection of two circles
   * whose centres are separated by dist
   * and have radius r1 andf r2
   */
  double r = r1;
  double R = r2;
  double d = dist;
  if (R < r) swap(r, R);
  double p1 = r*r*acos((d*d+r*r-R*R)/(2*d*r));
  double p2 = R*R*acos((d*d+R*R-r*r)/(2*d*R));
  double p3 = 0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));
  double area = p1 + p2 - p3;
  if (area > 0.0) return area;
  return 0.0;
}