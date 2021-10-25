#pragma once
#include "../general.h"

ll phi(ll n) {
  ll res = n, a = n;
  for (ll i = 2; i * i <= n; ++i) {
    if (a % i == 0) {
      res = res / i * (i - 1);
      while (a % i == 0) a /= i;
    }
  }
  if (a > 1) res = res / a * (a - 1);
  return res;
}