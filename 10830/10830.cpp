#include <iostream>
using namespace std;

int n;

struct col {
  long long arr[5];
  long long& operator[](int idx) {
    return arr[idx];
  }
  const long long& operator[](int idx) const {
    return arr[idx];
  }
};

struct Matrix {
  col arr[5];
  const col& operator[](int idx) const {
    return arr[idx];
  }
  col& operator[](int idx) {
    return arr[idx];
  }
};

Matrix operator*(const Matrix& a, const Matrix& b) {
  Matrix c = { 0 };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      long long sum = 0;
      for (int k = 0; k < n; k++) {
        sum = (sum % 1000 + b[i][k] % 1000 * a[k][j] % 1000) % 1000;
      }
      c[i][j] = sum % 1000;
    }
  }
  return c;
}

Matrix memo[201];
bool cal[201];

Matrix calc(Matrix a, unsigned long long square, int depth = 0) {
  if (square == 1) {
    return a;
  }
  if (cal[depth]) {
    return memo[depth];
  }
  cal[depth] = true;
  if (square & 1) {
    return memo[depth] = a * calc(a, square - 1, depth + 1);
  }
  return memo[depth] = calc(a, square >> 1, depth + 1) * calc(a, square >> 1, depth + 1);
}

int main() {
  unsigned long long b;
  cin >> n >> b;
  Matrix a = { 0 };
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  a=calc(a, b);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j]%1000 << ' ';
    }
    cout << '\n';
  }
  return 0;
}