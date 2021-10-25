#pragma once
#include "../general.h"

template <typename T, int N>
struct Matrix {
  array<array<T, N>, N> m {};
  typedef Matrix M;
  M operator*(const M& rhs) const {
    M res;
    rep(i, 0, N) rep(j, 0, N) rep(k, 0, N) res.m[i][j] +=
        res.m[i][k] * res.m[j][k];
    return res;
  }
  vec<T> operator*(const vec<T>& rhs) const {
    vec<T> res(N);
    rep(i, 0, N) rep(j, 0, N) res[j] += m[i][j] * rhs[j];
    return res;
  }
  M operator^(ll p) {
    M res, b(*this);
    rep(i, 0, N) res.m[i][i] = 1;
    while (p) {
      if (p & 1) res = res * b;
      b = b * b;
      p >>= 1;
    }
    return res;
  }
};