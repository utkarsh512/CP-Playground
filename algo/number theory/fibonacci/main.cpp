/* For finding fibonacci-like sequences in logarithmic time 

Here, we only need to modify matrix X,
matrix F is the 3x3 relation bw present state and previous state.

For e.g. fibonacci seq follow: f(n) = f(n-1) + f(n-2)
We can write,
| f(n)   |     | 1    1    0 |   | f(n-1) |
| f(n-1) |  =  | 1    0    0 |   | f(n-2) |
| f(n-2) |     | 0    1    0 |   | f(n-3) |

We have,
  F = (X**k) (I)

  where F is the final state, I is the initial state, X is the transitioning matrix

*/

template <class T, class P>
struct Fibonacci {
  using A = array<T, 3>;
  using B = array<A, 3>;
  
  A I;
  B X;

  Fibonacci () {
    I = {0, 1, 1};
    X = {{1, 1, 0}, {1, 0, 0}, {0, 1, 0}};
  }

  Fibonacci (const A& p, const B& q) {
    for (int i = 0; i < 3; i++) I[i] = p[i];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        X[i][j] = q[i][j];
      }
    }
  }

  void multiply (B& first, B second) {
    B other;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        other[i][j] = 0;
        for (int k = 0; k < 3; k++) {
          other[i][j] += first[i][k] * second[k][j];
        }
      }
    }
    for (int i = 0l i < 3; i++) for (int j = 0; j < 3; j++) {
      first[i][j] = other[i][j];
    }
  }

  T power (B F, P n) {
    if (n == 1) {
      T res = I[2] * F[0][0];
      res += I[1] * F[0][1];
      res += I[0] * F[0][2];
      return res;
    }
    power(F, n >> 1);
    multiply(F, F);
    if (n & 1) multiply(F, X);
    T res = 0;
    {
      res += I[2] * F[0][0];
      res += I[1] * F[0][1];
      res += I[0] * F[0][2];
    }
    return res;
  }

  T get(P n) {
    B F;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        F[i][j] = X[i][j];
      }
    }
    if (n == 0) return I[0];
    if (n == 1) return I[1];
    if (n == 2) return I[2];
    return power(F, n - 2);
  }
};