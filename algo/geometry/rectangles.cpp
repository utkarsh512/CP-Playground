#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define double long double
#define ac(x, i) get<i>(x)

/* Geometry */

int overlappingArea (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	/**
	 * Returns area of rectangle which is formed due to overlap of two rectangles
	 * Rectangle1 - bottom left (x1, y1) & top right (x2, y2)
	 * Rectangle2 - bottom left (x3, y3) & top right (x4, y4)
	 */
	if (x3 >= x2 || y3 >= y2 || x1 >= x4 || y1 >= y4) return 0;
  return (min(x2, x4) - max(x1, x3)) * (min(y2, y4) - max(y1, y3));
}

tuple <int, int, int, int> coordofOverlappingArea (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  /**
	 * Returns coordinate of bottom left and top right corner of rectangle which is formed due to overlap of two rectangles
	 * Rectangle1 - bottom left (x1, y1) & top right (x2, y2)
	 * Rectangle2 - bottom left (x3, y3) & top right (x4, y4)
	 */
  tuple<int ,int ,int, int> t;
  ac(t, 0) = max(x1, x3);
  ac(t, 1) = max(y1, y3);
  ac(t, 2) = min(x2, x4);
  ac(t, 3) = min(y2, y4);
  return t;
}

int overlappingAreaContrained (int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int p, int q, int r, int s) {
  /**
   * Returns area of (region which is formed due to overlap of two rectangles) UNION (third reactangle)
	 * Rectangle1 - bottom left (x1, y1) & top right (x2, y2)
	 * Rectangle2 - bottom left (x3, y3) & top right (x4, y4)
   * Rectangle3 - bottom left (p, q)   & top right (r, s)
   */
  tuple<int, int, int ,int> t = coordofOverlappingArea(x1, y1, x2, y2, x3, y3, x4, y4);
  if (ac(t, 2) <= ac(t, 0)) return 0;
  if (ac(t, 3) <= ac(t, 1)) return 0;
  return overlappingArea(p, q, r, s, ac(t,0), ac(t,1), ac(t,2), ac(t,3));
}