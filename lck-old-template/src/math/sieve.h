#pragma once
#include "../general.h"

vec<int> prime_sieve(int n) {
  vec<bool> vis(n + 1);
  vec<int> prime;
  rep(i, 2, n + 1) {
    if (!vis[i]) prime.pb(i);
    for (int x : prime) {
      if (i * x > n) break;
      vis[i * x] = 1;
      if (i % x == 0) break;
    }
  }
  return prime;
}

template <typename F, typename P, typename T = result_of_t<F>>
vec<int> mult_sieve(int n, T f1, F fp, P pp) {
  vec<int> res(n + 1), prime;
  vec<bool> vis(n + 1);
  res[1] = f1;
  rep(i, 2, n + 1) {
    if (!vis[i]) {
      prime.pb(i);
      res[i] = fp(i);
    }
    for (int x : prime) {
      if (i * x > n) break;
      vis[i * x] = 1;
      if (i % x == 0) {
        res[i * x] = pp(i, x, res[i], res[x]);
        break;
      }
      res[i * x] = res[i] * res[x];
    }
  }
  return res;
}

vec<int> phi_sieve(int n) {
  auto fp = [](int p) -> int { return p - 1; };
  auto pp = [](int x, int y, int fx, int fy) -> int { return fx * y; };
  return mult_sieve(n, 1, fp, pp);
}